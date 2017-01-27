

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include <sys/mman.h>

#include "shx.h"

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
  xcode (SHX, SHX_SIZE);
  return 0;  
}

