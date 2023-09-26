#ifndef TERM_H
#define TERM_H

#include <stdint.h>
#include <stddef.h>  //size_t

//TERMINAL VIDEO functions

//Color scheme for video mem
#define BLACK_COLOR 0x0 //BLACK
#define BLUE_COLOR 0x3 //BLUE

void str_print(const char* str);

#endif