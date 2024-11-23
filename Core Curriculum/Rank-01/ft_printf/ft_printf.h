#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int ft_printf(const char *format, ...);
int print_char(int c);
int print_str(char *str);
int print_digit(long n, int base, int uppercase);
int print_unsigned_digit(unsigned long n, int base, int uppercase);
int print_pointer(void *ptr);

#endif
