

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif
HMODULE LoadLibraryAX(LPCTSTR lpFileName);
#ifdef __cplusplus
}    
#endif

int main(void)
{
  HMODULE k32, k32x;
  
  k32  = LoadLibraryA("ws2_32");
  k32x = LoadLibraryAX("ws2_32");
  
  printf ("\nLoadLibraryA  : %p\nLoadLibraryAX : %p\n", k32, k32x);
  return 0;
}
