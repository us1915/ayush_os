#include "memory.h"
#include "block_heap/block_heap.h"

void* malloc(size_t size){

    return heap_alloc(size);
}

void free(void* ptr){

    heap_free(ptr);
}

void* memset(void* ptr, int val, size_t size){

    char* char_p = (char*)ptr;
    for(int i=0; i<size; i++){
        *(char_p + i) = (char)val;
    }

    return ptr;

}