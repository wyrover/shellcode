@echo off
yasm -f%1 x84.asm -ox84.obj
cl /DTEST /DASM getapi.c x84.obj
del *.obj