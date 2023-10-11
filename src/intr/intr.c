#include "intr.h"
#include "kernel.h"
#include "memory/memory.h"
#include "term/term.h"
#include "io/io.h"


struct intr_desc interrupt_desciptors[TOTAL_INTERRUPTS];
struct intr_desc_tr interrupt_descriptr_tr;

//Defined in intr.asm
extern void intr_load(void*ptr);
extern void int_keyboard();
extern void no_intr();

void no_intr_handler(){

    outb(0x20, 0x20);
}

void int_keyboard_handler(){

    str_print("Keyboard pressed!\n");

    outb(0x20, 0x20);
}

//Divide by zero fault
void intr_divide_by_zero(){

    str_print("Divide by zero error\n");
}

void intr_set(int intr_num, void* intr_address){

    struct intr_desc* pIntr_desc =  &interrupt_desciptors[intr_num];

    pIntr_desc->offset_1 = (uint32_t)intr_address & 0xFFFF;

    //From kenel.asm
    //CODE_SEG equ 0x08
    //DATA_SEG equ 0x10

    pIntr_desc->selector = 0x08;  //kernel code selector
    pIntr_desc->unused = 0x00;

    // Check DPL NOTE: wiki.osdev.org/Interupt_Descriptor_Table
    // 0b110 0xE 80386 32 bit Interrupt gate 
    // Present set to 1
    pIntr_desc->desc_attr = 0xEE;
    pIntr_desc->offset_2 =   (uint32_t)intr_address >> 16;

}

void intr_desc_init(){


    memset(interrupt_desciptors, 
    0, 
    sizeof(interrupt_desciptors));

    interrupt_descriptr_tr.limit = sizeof(interrupt_desciptors) - 1;
    interrupt_descriptr_tr.base = (uint32_t)interrupt_desciptors;

    for(int i=0;i<TOTAL_INTERRUPTS;i++){
        intr_set(i, no_intr);

    }

    //intr_set(0, intr_divide_by_zero);
   
    //0x20 timer interrupt
    //0x21 keyboard interrupt
    intr_set(0x20, int_keyboard_handler);

    //Load the intr descriptor table
    intr_load((void*)&interrupt_descriptr_tr);

}




