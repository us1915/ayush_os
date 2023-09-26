#include "kernel.h"
#include "intr/intr.h"


//////////////////////////////
//VIDEO MEM
//Color scheme for video mem
#define BLACK_COLOR 0x0 //BLACK
#define BLUE_COLOR 0x3 //BLUE

uint16_t char_create(const char character, const char color){
    return (color<<8|character);
}

size_t str_length(const char* str){
    size_t str_len = 0;
    
    while(str[str_len]){

        str_len++;
    }

    return str_len;
}

void str_print(const char* str){

    uint16_t* video_mem = (uint16_t*) (0xB8000);

    for(int i=0;i< str_length(str);i++){
        video_mem[i] = char_create(str[i], BLUE_COLOR);    
    }
}

///////////////////////////////
extern void intr_divide_by_zero_test();

void kernel_main(){

    //Render title on Boot screen
    str_print("Ayush_OS initializing... August 2023 (c)");


    //Initialialize Interrupt Table
    intr_desc_init(); 

    //Interrupt fault test for divide by zero
    intr_divide_by_zero_test();

}
