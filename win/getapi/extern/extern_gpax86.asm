;
;  Copyright © 2017 Odzhan. All Rights Reserved.
;
;  Redistribution and use in source and binary forms, with or without
;  modification, are permitted provided that the following conditions are
;  met:
;
;  1. Redistributions of source code must retain the above copyright
;  notice, this list of conditions and the following disclaimer.
;
;  2. Redistributions in binary form must reproduce the above copyright
;  notice, this list of conditions and the following disclaimer in the
;  documentation and/or other materials provided with the distribution.
;
;  3. The name of the author may not be used to endorse or promote products
;  derived from this software without specific prior written permission.
;
;  THIS SOFTWARE IS PROVIDED BY AUTHORS "AS IS" AND ANY EXPRESS OR
;  IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
;  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
;  DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
;  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
;  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
;  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
;  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
;  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
;  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
;  POSSIBILITY OF SUCH DAMAGE.
;

    bits 32

struc pushad_t
  _edi resd 1
  _esi resd 1
  _ebp resd 1
  _esp resd 1
  _ebx resd 1
  _edx resd 1
  _ecx resd 1
  _eax resd 1
  .size:
endstruc

; macro that converts string to lowercase 
%macro cmpms 1.nolist
  %assign %%h 0  
  %strlen %%len %1
  %assign %%i 1
  
  %rep %%len
    %substr %%c %1 %%i
    %assign %%h ((%%h << 13) & 0FFFFFFFFh) | (%%h >> (32-13))
    %assign %%c (%%c | 0x20)    
    %assign %%h ((%%h + %%c) & 0FFFFFFFFh)
    %assign %%i (%%i+1)
  %endrep
  db 081h, 0fah
  dd %%h
%endmacro

; returns GetProcAddress in ebp
extern_gpa:
    int3
    pushad
    push   30h
    pop    edx

    mov    esi, [fs:edx]  ; eax = (PPEB) __readfsdword(0x30);
    mov    esi, [esi+0ch] ; eax = (PMY_PEB_LDR_DATA)peb->Ldr
    mov    edi, [esi+0ch] ; edi = ldr->InLoadOrderModuleList.Flink
    jmp    gapi_l3
gapi_l0:
    movzx  ecx, word[edi+44]  ; ecx = BaseDllName.Length
    mov    esi, [edi+48]      ; esi = BaseDllName.Buffer
    shr    ecx, 1
    xor    eax, eax
    cdq
gapi_l1:
    lodsw
    or     al, 0x20
    ror    edx, 13
    add    edx, eax
    loop   gapi_l1
    ; target DLL?
    cmpms  "advapi32.dll"
    jne    gapi_l2    
   
    ; edx += IMAGE_DOS_HEADER.e_lfanew
    mov    edx, [ebx+3ch]
    add    edx, [esp+_edx]   
    mov    esi, [ebx+edx+50h]
    add    esi, ebx
imp_l0:
    lodsd                   ; OriginalFirstThunk +00h
    xchg   eax, ebp         ; store in ebp
    lodsd                   ; TimeDateStamp      +04h
    lodsd                   ; ForwarderChain     +08h
    lodsd                   ; Name               +0Ch
    xchg   eax, edx         ; store in edx
    lodsd                   ; FirstThunk         +10h 
    xchg   eax, edi         ; store in edi
    
    mov    eax, [edx+ebx]
    or     eax, 20202020h   ; convert to lowercase
    cmp    eax, 'kern'
    jnz    imp_l0
    
    mov    eax, [edx+ebx+4]
    or     eax, 20202020h   ; convert to lowercase
    cmp    eax, 'el32'
    jnz    imp_l0
 
    lea    esi, [ebp+ebx]
    add    edi, ebx
imp_l1:
    lodsd                   ; eax = oft->u1.Function, oft++;
    scasd                   ; ft++;
    test   eax, eax
    jz     imp_l0           ; get next module if zero
    js     imp_l1           ; skip ordinals 
    
    cmp    dword[eax+ebx+2], 'GetP'
    jnz    imp_l1
    
    cmp    dword[eax+ebx+10], 'ddre'
    jnz    imp_l1
    
    mov    eax, [edi-4]     ; ebp = ft->u1.Function
    jmp    gapi_l4    
gapi_l2:
    mov    edi, [edi]     ; edi = dte->InMemoryOrderLinks.Flink
gapi_l3:    
    mov    ebx, [edi+18h] ; ebx = dte->DllBase
    test   ebx, ebx
    jnz    gapi_l0
    xchg   eax, ebx
gapi_l4:
    mov    [esp+_ebp], eax
    popad
    ret
