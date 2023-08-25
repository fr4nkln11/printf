#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int _printf(const char *format, ...);

int scan_format(const char *format, va_list arg_ptr);
int print_format(char specifier, va_list arg_ptr);

typedef struct specifier_structure
{
	char specifier;
	int (*specifier_function)(va_list);
} spec_t;

/* specifier function wrappers */
int spec_c(va_list arg_ptr);
int spec_s(va_list arg_ptr);
int spec_di(va_list arg_ptr);
int spec_b(va_list arg_ptr);

/* utilities */
int print_char(char character);
int print_string(char *string);
int print_base_digit(long number, int base);

#endif
