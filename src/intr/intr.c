#include "intr.h"
#include "kernel.h"
#include "memory/memory.h"

struct intr_desc interrupt_desciptors[TOTAL_INTERRUPTS];
struct intr_desc_tr interrupt_descriptr_tr;

//Defined in intr.asm
extern void intr_load(void*ptr);

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

    //Use 32 for intr num
    intr_set(32, intr_divide_by_zero);

    //Load the intr descriptor table
    intr_load((void*)&interrupt_descriptr_tr);

}




