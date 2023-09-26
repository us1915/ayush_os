#ifndef INTR_H
#define INTR_H

#include <stdint.h>

//Reference: wiki.osdev.org/Interrupt_Descriptor_Table

#define TOTAL_INTERRUPTS 0x200

//Interrupt descript Table structures
struct intr_desc {

    uint16_t offset_1; // offset 0 - 15
    uint16_t selector; // selector
    uint8_t unused; //unused set to 0
    uint8_t desc_attr; //descriptor type and attributes
    uint16_t offset_2; // offset 16 - 31
} __attribute__((packed));

struct intr_desc_tr {

    uint16_t limit; // size of descriptor table -1  0x200 = 512 total intrs
    uint32_t base; // base address of the start of the Intr desc table
}__attribute__((packed));


void intr_desc_init();

#endif