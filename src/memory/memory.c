#include "memory.h"

void* memset(void* p, int val, size_t size){

    char* char_p = (char*)p;
    for(int i=0; i<size; i++){
        *(char_p + i) = (char)val;
    }

    return p;

}