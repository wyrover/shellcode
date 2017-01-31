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

    %ifndef BIN
      global GetProcAddressX
      global _GetProcAddressX
    %endif
    
; FARPROC WINAPI GetProcAddressX(HMODULE hModule, LPCSTR lpProcName);    
GetProcAddressX:
_GetProcAddressX:
    pushad
    push   30h
    pop    edx
    mov    ebx, [fs:edx]      ; ebx = peb
    mov    ebx, [ebx+08h]     ; ebx = ImageBaseAddress
    add    edx, [ebx+3ch]     ; eax = e_lfanew
    mov    ebp, [ebx+edx+50h]
    add    ebp, ebx
imp_l0:
    mov    esi, ebp
    lodsd                     ; OriginalFirstThunk +00h
    xchg   eax, edx           ; temporarily store in edx
    lodsd                     ; TimeDateStamp      +04h
    lodsd                     ; ForwarderChain     +08h
    lodsd                     ; Name               +0Ch
    test   eax, eax           ; end of modules?
    jz     imp_l2
    
    lodsd                     ; FirstThunk
    mov    ebp, esi           ; ebp = next descriptor

    lea    esi, [edx+ebx]     ; esi = OriginalFirstThunk + base
    lea    edi, [eax+ebx]     ; edi = FirstThunk + base
imp_l1:
    lodsd                     ; eax = oft->u1.Function, oft++;
    scasd                     ; ft++;
    test   eax, eax
    jz     imp_l0             ; get next module if zero
    js     imp_l1             ; skip ordinals 
    
    cmp    dword[eax+ebx+2], 'GetP'
    jnz    imp_l1
    
    cmp    dword[eax+ebx+10], 'ddre'
    jnz    imp_l1
    
    mov    eax, [edi-4]       ; eax = ft->u1.Function
imp_l2:    
    mov    [esp+1ch], eax     ;   
    popad                     
    test   eax, eax
    jz     imp_l3
    jmp    eax                ; GetProcAddress()
imp_l3:
    ret    2*4
        