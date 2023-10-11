# ayush_os
32 bit multitasking OS from scratch for x86 for neuromorphic computing

NOTES:

qemu-system-x86-64 -hda ./bin/os.bin

** GDB **

$ gdb
GNU gdb (Ubuntu 12.1-0ubuntu1~22.04) 12.1
Copyright (C) 2022 Free Software Foundation, Inc.

(gdb) add-symbol-file ./build/kernelfull.o  0x100000
add symbol table from file "./build/kernelfull.o" at
	.text_addr = 0x100000
(y or n) y
Reading symbols from ./build/kernelfull.o...

(gdb) target remote | qemu-system-x86_64 -hda ./bin/os.bin -gdb stdio -S
Remote debugging using | qemu-system-x86_64 -hda ./bin/os.bin -gdb stdio -S
0x000000000000fff0 in ?? ()

(gdb) break kernel.c:20
Breakpoint 1 at 0x100218: file ./src/kernel.c, line 20.

(gdb) c
Continuing.

Breakpoint 1, kernel_main () at ./src/kernel.c:20
20	    outb(0x60, 0xFE);
(gdb) layout asm

(gdb) stepi
(gdb) print $eax
$1 = 255
(gdb) print $edx
$2 = 96

Detaching from pid process 1
Ending remote debugging.

** Resources **

General Computing:
https://wiki.osdev.org/Main_Page

Neuromorphic Computing:
https://www.nature.com/articles/s43588-021-00184-y
https://www.intel.com/content/www/us/en/research/neuromorphic-computing.html
https://www.humanbrainproject.eu/en/science-development/focus-areas/neuromorphic-computing/










