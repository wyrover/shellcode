
// based on idea by Joshua Pitts
// if we know GetProcAddress and LoadLibraryA
// are accessible from Import Directory, we look
// in kernel32.dll
//
// odzhan

#include "getapi.h"

int main(void)
{
  DWORD                    rva;
  PIMAGE_IMPORT_DESCRIPTOR imp;
  PIMAGE_DOS_HEADER        dos;
  PDWORD                   name;
  PIMAGE_THUNK_DATA        oft, ft;
  PIMAGE_IMPORT_BY_NAME    ibn;  
  PIMAGE_NT_HEADERS        nt;
  PIMAGE_DATA_DIRECTORY    dir;
  LPVOID                   base, module, gpa;
  PDWORD                   dll, api;
  PPEB                     peb;

#if defined(_WIN64)
  peb = (PPEB) __readgsqword(0x60);
#else
  peb = (PPEB) __readfsdword(0x30);
#endif

  base = peb->ImageBaseAddress;
  dos  = (PIMAGE_DOS_HEADER)base;
  nt   = RVA2VA(PIMAGE_NT_HEADERS, base, dos->e_lfanew);
  dir  = (PIMAGE_DATA_DIRECTORY)nt->OptionalHeader.DataDirectory;
  rva  = dir[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress;  
  imp  = (PIMAGE_IMPORT_DESCRIPTOR) RVA2VA(ULONG_PTR, base, rva);
  
  // locate kernel32.dll
  for (;;) {
    dll   = RVA2VA(PDWORD, base, imp->Name);
    if ((dll[0] | 0x20202020) == 'nrek') break;
    imp++;
  } 
  // now locate GetProcAddress
  rva   = imp->OriginalFirstThunk;
  oft   = (PIMAGE_THUNK_DATA)RVA2VA(ULONG_PTR, base, rva);
  
  rva   = imp->FirstThunk;
  ft    = (PIMAGE_THUNK_DATA)RVA2VA(ULONG_PTR, base, rva);
    
  for (gpa=NULL;; oft++, ft++) 
  {
    rva  = oft->u1.AddressOfData;
    ibn  = (PIMAGE_IMPORT_BY_NAME)RVA2VA(ULONG_PTR, base, rva);
    name = (PDWORD)ibn->Name;
    
    // is this GetProcAddress?
    if (name[0] == 'PteG' && name[2] == 'erdd') {
      gpa = (LPVOID)ft->u1.Function;
      break;
    }
  }
  
  printf ("\nGetProcAddress : %p\n", gpa);
  return 0;
}




