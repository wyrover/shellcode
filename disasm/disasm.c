/**
  Copyright © 2015-2017 Odzhan. All Rights Reserved.

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

#if defined(_WIN32) || defined(_WIN64)
#define WINDOWS
#endif
  
#ifdef _MSC_VER
#pragma warning(disable : 4005)
#endif
  
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#include <sys/stat.h>

#ifdef WINDOWS
#include <windows.h>
#include <shlwapi.h>
#else
#include <sys/mman.h> 
#endif

//#include <inttypes.h>

#include <capstone/capstone.h>
#include <capstone/platform.h>

#define ASM_OUT 0
#define C_OUT   1

#pragma comment (lib, "shlwapi.lib")
#pragma comment (lib, "user32.lib")
#pragma comment (lib, "capstone\\capstone.lib")
 
// output format options 
typedef struct opt_fmt_t {
  int n;
  char *s;
} format_t;

format_t opt_formats[]=
{{ASM_OUT, "asm"},
 {C_OUT,   "c"}};
 
// syntax options
typedef struct opt_syntax_t {
  int n;
  char *s;
} syntax_t;

syntax_t opt_syntax[]=
{{CS_OPT_SYNTAX_INTEL, "intel"},
 {CS_OPT_SYNTAX_ATT,   "att"}};
  
// cpu mode options 
typedef struct opt_mode_t {
  int n;
  char *s;
} mode_t;
  
mode_t opt_mode[]=
{{CS_MODE_16, "16"},
 {CS_MODE_32, "32"},
 {CS_MODE_64, "64"}}; 
 
// architecture options
typedef struct _arch_opt_t {
  int n;
  char *s;
} arch_t;

arch_t opt_arch[]=
{{CS_ARCH_ARM,   "arm"  },
 {CS_ARCH_ARM64, "arm64"},
 {CS_ARCH_MIPS,  "mips" },
 {CS_ARCH_PPC,   "ppc"  },
 {CS_ARCH_SPARC, "sparc"},
 {CS_ARCH_SYSZ,  "sysz" },
 {CS_ARCH_X86,   "x86"  },
 {CS_ARCH_XCORE, "xcore"}};
 
// disassembly options
typedef struct disasm_opt_t {
  int    arch, mode, syntax;
  int    ofs, hex, fmt;
  char   *file;
  #ifdef WINDOWS
    HANDLE fd, map;
    LPVOID *mem;
  #else
    int    fd, map;
    void   *mem;
  #endif
  size_t size;
  int max_op, max_mnc, max_bytes;
} disasm_opt;
 
void get_max(disasm_opt *opt) 
{
  csh           handle;
  uint64_t      address=0;
  cs_insn       *insn;
  const uint8_t *code = (const uint8_t*)opt->mem;
  size_t        code_len = opt->size;
  size_t        len;
  
  cs_open(opt->arch, opt->mode, &handle);
  
  cs_option(handle, CS_OPT_SYNTAX, opt->syntax);
  
  insn = cs_malloc(handle);
  
  while (cs_disasm_iter(handle, &code, 
    &code_len, &address, insn)) 
  {
    len = strlen(insn->op_str);    
    opt->max_op    = (len>opt->max_op) ? len : opt->max_op; 
    
    len = strlen(insn->mnemonic);
    opt->max_mnc   = (len>opt->max_mnc) ? len : opt->max_mnc;
    
    len = insn->size;
    opt->max_bytes = (len>opt->max_bytes) ? len : opt->max_bytes;
   
  }
  cs_free(insn, 1);
  cs_close(&handle);    
}
  
// get maximum instruction length
void disasm (disasm_opt *opt) 
{
  csh           handle;
  uint64_t      address=0;
  cs_insn       *insn;
  const uint8_t *code = (const uint8_t*)opt->mem;
  size_t        code_len = opt->size;
  uint32_t      insn_max, asm_max;
  int           len, ofs, i;
  const uint8_t *hex;
  char          ins[64];
  
  get_max(opt);
  
  insn_max = opt->max_bytes * 4;
  asm_max  = (opt->max_op + opt->max_mnc) + 1;
  
  cs_open(opt->arch, opt->mode, &handle);
  
  cs_option(handle, CS_OPT_SYNTAX, opt->syntax);
  
  insn = cs_malloc(handle);
  
  while (cs_disasm_iter(handle, &code, 
    &code_len, &address, insn)) 
  {
    len = insn->size;
    ofs = insn->address;
    
    _snprintf(ins, sizeof(ins), "%-*s %s", 
        opt->max_mnc, insn->mnemonic, insn->op_str);
    
    putchar('\n');
    
    // print the offset if required
    if (opt->ofs) {
      printf ("  /* %04X */ ", ofs);
    }
    
    // print hex bytes
    putchar ('\"');
    for (i=0; i<len; i++) {
      printf ("\\x%02x", insn->bytes[i]);
    }
    putchar ('\"');
    len*=4;
    
    // pad remainder with spaces
    while (len++ < insn_max) putchar (' ');
    
    // print asm string
    printf (" /* %-*s */", asm_max, ins);    
  }
  cs_free(insn, 1);
  cs_close(&handle);  
}

#ifdef WINDOWS
void xstrerror (char *fmt, ...) 
{
  char    *error=NULL;
  va_list arglist;
  char    buffer[2048];
  DWORD   dwError=GetLastError();
  
  va_start (arglist, fmt);
  wvnsprintf (buffer, sizeof(buffer) - 1, fmt, arglist);
  va_end (arglist);
  
  if (FormatMessage (
      FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
      NULL, dwError, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), 
      (LPSTR)&error, 0, NULL))
  {
    printf ("[ %s : %s\n", buffer, error);
    LocalFree (error);
  } else {
    printf ("[ %s : %i\n", buffer, dwError);
  }
}

int map_file (disasm_opt *opt) 
{
  int r = 0;
  
  opt->fd = CreateFile (opt->file, GENERIC_READ, 
      FILE_SHARE_READ, NULL, OPEN_EXISTING, 
      FILE_ATTRIBUTE_NORMAL, NULL);
  
  if (opt->fd != INVALID_HANDLE_VALUE)
  {
    opt->size = GetFileSize(opt->fd, 0);
    
    opt->map = CreateFileMapping (opt->fd, NULL, 
        PAGE_READONLY, 0, 0, NULL);
    if (opt->map != NULL) 
    {
      opt->mem = MapViewOfFile (opt->map, 
        FILE_MAP_READ, 0, 0, 0);
        
      r = (opt->mem != NULL);  
    } else {
      xstrerror("CreateFileMapping");
    }      
  } else {
    xstrerror("CreateFile");
  }
  return r;  
}

void unmap_file (disasm_opt *opt) {
  UnmapViewOfFile ((LPCVOID)opt->mem);
  CloseHandle ((HANDLE)opt->map);
  CloseHandle ((HANDLE)opt->fd);  
}

#else
// 
int map_file (disasm_opt *opt) {
  
  int r = 0;
  
  // open file for reading
  opt->fd = open(f, O_RDONLY);
  
  if (opt->fd > 0) {
    // get size of file
    r = fstat(fd, &s);
    if (r > 0) {
      opt->size = s.st_size;
      // map file into memory
      opt->mem = mmap(0, opt->size, 
          PROT_READ, 0, opt->fd, 0);
      r = (opt->mem != MAP_FAILED);    
    }
    if (!r) close(opt->fd);
  }
  return r;
}

// 
void unmap_file(disasm_opt *opt) {
  close(opt->fd);
}
#endif

void usage(void)
{
  printf ("\nusage: disasm [options] <file>\n");
  printf ("\n  -c <cpu>     CPU to disassemble for");
  printf ("\n  -m <mode>    CPU mode"); 
  printf ("\n  -s <syntax>  Syntax format for x86: ATT, INTEL (default)");  
  printf ("\n  -f <format>  Output format: C, ASM");
  printf ("\n  -o           Don't display offsets"); 
  printf ("\n  -x           Don't display hex bytes\n"); 
  exit(0);
} 

/**F****************************************/
char* get_param (int argc, char *argv[], int *i)
{
  int n=*i;
  
  if (argv[n][2] != 0) {
    return &argv[n][2];
  }
  if ((n+1) < argc) {
    *i=n+1;
    return argv[n+1];
  }
  printf ("[ %c%c requires parameter\n", 
      argv[n][0], argv[n][1]);
      
  exit (0);
}

int get_format(int argc, char *argv[], int *idx)
{
  int  i;
  char *format=get_param(argc, argv, idx);
  
  for (i=0; i<sizeof(opt_formats)/sizeof(format_t); i++) {
    if (strcmp(opt_formats[i].s, format)==0) {
      return opt_formats[i].n;
    }
  }
  return -1;
}

int get_arch(int argc, char *argv[], int *idx)
{
  int  i;
  char *arch=get_param(argc, argv, idx);;
  
  for (i=0; i<sizeof(opt_arch)/sizeof(arch_t); i++) {
    if (strcmp(opt_arch[i].s, arch)==0) {
      return opt_arch[i].n;
    }
  }
  return -1;
}

int get_mode(int argc, char *argv[], int *idx)
{
  int  i;
  char *mode=get_param(argc, argv, idx);;
  
  for (i=0; i<sizeof(opt_mode)/sizeof(mode_t); i++) {
    if (strcmp(opt_mode[i].s, mode)==0) {
      return opt_mode[i].n;
    }
  }
  return -1;
}

int get_syntax(int argc, char *argv[], int *idx)
{
  int  i;
  char *syntax=get_param(argc, argv, idx);;
  
  for (i=0; i<sizeof(opt_syntax)/sizeof(syntax_t); i++) {
    if (strcmp(opt_syntax[i].s, syntax)==0) {
      return opt_syntax[i].n;
    }
  }
  return -1;
}

int main (int argc, char *argv[])
{
  disasm_opt opt;
  char       c;
  int        i;
  
  // zero initialize options
  memset(&opt, 0, sizeof(opt));
  
  // set default
  opt.arch   = CS_ARCH_X86;
  opt.mode   = CS_MODE_32;
  opt.syntax = CS_OPT_SYNTAX_INTEL;
  opt.ofs    = 1;
  opt.hex    = 1;
  
  // for each argument
  for (i=1; i<argc; i++)
  {
    // is this option?
    if (argv[i][0]=='-' || argv[i][1]=='/')
    {
      // get option
      c=argv[i][1];
      
      switch (c)
      {
        case 'a':
          opt.arch=get_arch(argc, argv, &i);
          break;
        case 'm':     // cpu mode
          opt.mode=get_mode(argc, argv, &i);
          break;
        case 'f':     // output format
          opt.fmt=get_format(argc, argv, &i);
          break;
        case 'o':     // don't display offsets
          opt.ofs=0;
          break;
        case 's':     // syntax
          opt.syntax=get_syntax(argc, argv, &i);
          break;          
        case 'x':     // don't display hex bytes
          opt.hex=0;
          break;
        case '?':     // display usage
        case 'h':
          usage ();
        default:
          printf ("  [ unknown option %c\n", c);
          break;
      }
    } else {
      // assume it's a file
      opt.file = argv[i];
    }
  }
  
  if (opt.file == NULL) {
    usage();   
  }
  
  if (map_file (&opt))
  {
    disasm(&opt);
    unmap_file(&opt);
  }
  return 0;
}

