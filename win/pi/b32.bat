@echo off
yasm -fbin -DBIN asm\ExecPIC.asm -o ExecPIC.bin
yasm -fbin -DBIN asm\LoadDLLPIC.asm -o LoadDLLPIC.bin
yasm -fbin -DBIN asm\CreateThreadPIC.asm -o CreateThreadPIC.bin
disasm -b64 -fc ExecPIC.bin >winexec.h
disasm -b64 -fc LoadDLLPIC.bin >loadlib.h
disasm -b64 -fc CreateThreadPIC.bin >createthread.h
cl /nologo /c pi.c 
link /nologo /subsystem:console pi.obj /out:pi32.exe
del *.obj