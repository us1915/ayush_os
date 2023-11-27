#include "kernel.h"
#include "intr/intr.h"
#include "term/term.h"
#include "io/io.h"

#include "memory/block_heap/block_heap.h"

extern void intr_divide_by_zero_test();

void kernel_main(){

    //Render title on Boot screen
    str_print("Ayush_OS initializing... August 2023 (c)");


    //Initialialize Interrupt Table
    intr_desc_init(); 

    //Initialize Heap memory
    heap_init();

    //Interrupt fault test for divide by zero
    //intr_divide_by_zero_test();

    //outb(0x60, 0xFE);

}
