#ifndef BLOCK_HEAP_H
#define BLOCK_HEAP_H

#include <stddef.h>
#include <stdint.h>

#define INIT_ADDRESS 0x01000000
#define MAX_MEMORY 40960000 //40MB
#define ALIGNMENT 4096 //Block size

//Allow using only 1000 blocks = 10000 x 4096 = 40960000.
#define BLOCK_COUNT (MAX_MEMORY/ALIGNMENT)

typedef struct block {

    uint8_t num_used_blocks;
    uint32_t address;
} block;


typedef struct pool{

    int num_used_blocks; //statistics??

    struct block heap_blocks[BLOCK_COUNT];

} pool;

void heap_init();
void* heap_alloc(size_t sz);
void heap_free(void* ptr);

#endif