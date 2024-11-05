#include <stddef.h>

void *ft_memset(void *ptr, int value, size_t num) {
    unsigned char *p = (unsigned char *)ptr; 
    size_t c;

    for (c = 0; c < num; c++) {
        p[c] = (unsigned char)value; 
    }
    
    return ptr; 
}
