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

    bits 64
    
; returns    
;   rbx = pointer to LoadLibraryA    
;   rbp = pointer to GetProcAddress    
get_lla_gpa:
_get_lla_gpa:
    push   60h
    pop    rdx
    mov    rbx, [gs:rdx]     ; ebx = peb
    mov    rbx, [rbx+08h]    ; ebx = ImageBaseAddress
    add    rdx, [rbx+3ch]    ; eax = e_lfanew
    mov    esi, [rbx+rdx+50h]
    add    rsi, rbx
imp_l0:
    lodsd                    ; OriginalFirstThunk +00h
    xchg   eax, ebp          ; store in ebp
    lodsd                    ; TimeDateStamp      +04h
    lodsd                    ; ForwarderChain     +08h
    lodsd                    ; Name               +0Ch
    xchg   eax, edx          ; store in edx
    lodsd                    ; FirstThunk         +10h 
    xchg   eax, edi          ; store in edi
    
    mov    rax, [rdx+rbx]
    or     eax, 20202020h    ; convert to lowercase
    cmp    eax, 'kern'
    jnz    imp_l0
    
    shr    rax, 32
    or     eax, 20202020h    ; convert to lowercase
    cmp    eax, 'el32'
    jnz    imp_l0
    
    ; locate GetProcAddress
    mov    ecx, 'GetP'
    mov    edx, 'ddre'
    call   get_imp
    push   rax               ; save pointer 
    
    ; locate LoadLibraryA
    mov    ecx, 'Load'
    mov    edx, 'aryA'
    call   get_imp
    pop    rbp               ; ebp = GetProcAddress
    push   rax
    pop    rbx
    ret

get_imp:
    push   rsi
    push   rdi
    lea    rsi, [rbp+rbx]     ; esi = OriginalFirstThunk + base
    add    rdi, rbx           ; edi = FirstThunk + base
gi_l0:
    lodsq                     ; eax = oft->u1.Function, oft++;
    scasq                     ; ft++;
    test   rax, rax
    jz     gi_l1              ; get next module if zero
    js     gi_l0              ; skip ordinals 
    
    cmp    dword[rax+rbx+2], ecx
    jnz    gi_l0

    cmp    dword[rax+rbx+10], edx
    jnz    gi_l0
    
    mov    rax, [rdi-8]       ; eax = ft->u1.Function
gi_l1: 
    pop    rdi
    pop    rsi
    ret    
    