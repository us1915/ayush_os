#include "block_heap.h"

//heap pool init
struct pool heap_pool;
void heap_init(){

    heap_pool.num_used_blocks = 0;

    for(int i=0;i<BLOCK_COUNT;i++){

        heap_pool.heap_blocks[i].address = INIT_ADDRESS + (i * ALIGNMENT);
        heap_pool.heap_blocks[i].num_used_blocks = 0;
    }
}

void* heap_alloc(size_t sz){

    //Check sz at least block size
    size_t allocate_sz = sz;
    int num_blocks = 0;
    if(sz % ALIGNMENT) {
      allocate_sz = (sz/ALIGNMENT * ALIGNMENT) + ALIGNMENT;   
    }

    num_blocks = allocate_sz/ALIGNMENT;

    //Find the free block
    for(int i=0;i<BLOCK_COUNT;i++){

        //Check for overflow
        if( i + num_blocks >= BLOCK_COUNT){
            return 0;
        }

        if( !heap_pool.heap_blocks[i].num_used_blocks){
            heap_pool.heap_blocks[i].num_used_blocks = num_blocks;

            heap_pool.num_used_blocks += num_blocks;
            return (void*)heap_pool.heap_blocks[i].address;
        }
    }
    return 0;

}

void heap_free(void* ptr){

    //Find the allocated block
    for(int i=0;i<BLOCK_COUNT;i++){

        if(heap_pool.heap_blocks[i].address ==  (uint32_t)ptr){

            heap_pool.num_used_blocks -= heap_pool.heap_blocks[i].num_used_blocks;
            heap_pool.heap_blocks[i].num_used_blocks = 0;
            break;
        }
    }
    
}



