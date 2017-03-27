## About ##

**disasm** is a simple tool for creating C strings from shellcodes stored in binary format. It uses the [Capstone disassembler engine](http://www.capstone-engine.org/) which supports up to 8 CPU architectures.

Although Capstone supports multiple CPU architectures, only **SPARC**, **MIPS**, **ARM**, **POWERPC** and **X86** have been tested.

## Installing capstone ##

Unless already installed, you'll first need to clone capstone, build and install.
disasm uses the latest source from repository so if you've installed using a package manager or from ports, it may be outdated. 

	git clone https://github.com/aquynh/capstone

**32-bit MSVC**

    cd capstone
    cd msvc
    msbuild /p:Configuration=Release

There's already prebuilt library in **disasm\capstone** folder

**NIX**
 
    ./make.sh
    ./make.sh install

## Compiling ##

**MSVC**

    cl disasm.c -I.
    
    
## Examples ##

PowerPC 32-bit Big Endian

![alt text](https://github.com/odzhan/shellcode/blob/master/disasm/img/ppc32_be.png)

MIPS 32-bit Little Endian

![alt text](https://github.com/odzhan/shellcode/blob/master/disasm/img/mips32_le.png)

X86 32-bit 

![alt text](https://github.com/odzhan/shellcode/blob/master/disasm/img/x86_32.png)

X86 64-bit using AT&T Syntax

![alt text](https://github.com/odzhan/shellcode/blob/master/disasm/img/x86_64_att.png)

SPARC

![alt text](https://github.com/odzhan/shellcode/blob/master/disasm/img/sparc.png)

## Author ##

[@odzhancode](https://www.twitter.com/odzhancode "Follow me on Twitter")
 
3/5/2017 1:10:17 PM 