#ifndef MEMORY_H
#define MEMORY_H

#include <stddef.h>

void* malloc(size_t size);
void free(void* ptr);
void* memset(void* p, int val, size_t size);


#endif