/**
  Copyright © 2017 Odzhan. All Rights Reserved.

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

#include "getapi.h"

#define DLL_HASH 0x8FECD63F // kernel32.dll

LPVOID get_imp(PIMAGE_IMPORT_DESCRIPTOR imp, 
    LPVOID base, PDWORD api)
{
  PDWORD                   name;
  LPVOID                   api_adr;
  PIMAGE_THUNK_DATA        oft, ft;
  PIMAGE_IMPORT_BY_NAME    ibn;
  DWORD                    rva;
  
  rva   = imp->OriginalFirstThunk;
  oft   = (PIMAGE_THUNK_DATA)RVA2VA(ULONG_PTR, base, rva);
  
  rva   = imp->FirstThunk;
  ft    = (PIMAGE_THUNK_DATA)RVA2VA(ULONG_PTR, base, rva);
    
  for (;; oft++, ft++) 
  {
    // no API left?
    if (oft->u1.AddressOfData==0) break;
    // skip ordinals
    if (IMAGE_SNAP_BY_ORDINAL(oft->u1.Ordinal)) continue;
    
    rva  = oft->u1.AddressOfData;
    ibn  = (PIMAGE_IMPORT_BY_NAME)RVA2VA(ULONG_PTR, base, rva);
    name = (PDWORD)ibn->Name;
    
    // have we a match?
    if (name[0] == api[0] && name[1] == api[1]) {
      api_adr = (LPVOID)ft->u1.Function;
      break;
    }
  }
  return api_adr;  
}

int main(void)
{
  DWORD                    rva, hash;
  PIMAGE_IMPORT_DESCRIPTOR imp;
  PIMAGE_DOS_HEADER        dos;
  PDWORD                   name;
  PIMAGE_THUNK_DATA        oft, ft;
  PIMAGE_IMPORT_BY_NAME    ibn;  
  PIMAGE_NT_HEADERS        nt;
  PIMAGE_DATA_DIRECTORY    dir;
  LPVOID                   base, lla=NULL, gpa=NULL;
  PCHAR                    dll;
  PPEB                     peb;
  PPEB_LDR_DATA            ldr;
  PLDR_DATA_TABLE_ENTRY    dte;
  
#if defined(_WIN64)
  peb = (PPEB) __readgsqword(0x60);
#else
  peb = (PPEB) __readfsdword(0x30);
#endif

  ldr = (PPEB_LDR_DATA)peb->Ldr;
  
  // for each DLL loaded
  for (dte=(PLDR_DATA_TABLE_ENTRY)ldr->InLoadOrderModuleList.Flink;
       dte->DllBase != NULL && gpa == NULL; 
       dte=(PLDR_DATA_TABLE_ENTRY)dte->InLoadOrderLinks.Flink)
  {
    base = dte->DllBase;
    dos  = (PIMAGE_DOS_HEADER)base;
    nt   = RVA2VA(PIMAGE_NT_HEADERS, base, dos->e_lfanew);
    dir  = (PIMAGE_DATA_DIRECTORY)nt->OptionalHeader.DataDirectory;
    rva  = dir[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress;  
    imp  = (PIMAGE_IMPORT_DESCRIPTOR) RVA2VA(ULONG_PTR, base, rva);
  
    // locate the dll by hash
    for (;;imp++) 
    {
      rva = imp->Name;
      if (rva==0) {
        break;
      }
      dll = RVA2VA(PCHAR, base, rva);
      
      for (hash=0; *dll; dll++) {
        hash = ROTR32(hash, 13); 
        hash += *dll | 0x20;  
      }

      // is this the DLL we need?      
      if (hash == DLL_HASH) 
      { 
        // now locate GetProcAddress and LoadLibraryA
        lla = get_imp(imp, base, (PDWORD)"LoadLibraryA");
        gpa = get_imp(imp, base, (PDWORD)"GetProcAddress");
      }
    }
  }  
  printf ("\nGetProcAddress : %p"
          "\nLoadLibraryA   : %p\n", gpa, lla);
          
  printf ("\nGetProcAddress : %p"
          "\nLoadLibraryA   : %p\n", 
          GetProcAddress(LoadLibraryA("kernel32"), 
              "GetProcAddress"), 
              
          GetProcAddress(LoadLibraryA("kernel32"), 
             "LoadLibraryA"));
  return 0;
}
