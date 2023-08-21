#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int _printf(const char *format, ...);

int print_format(char specifier, va_list arg_ptr);

int print_char(char character);
int print_string(char *string);

#endif
