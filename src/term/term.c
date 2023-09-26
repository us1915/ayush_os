#include "term.h"


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