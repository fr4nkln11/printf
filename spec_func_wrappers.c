#include "main.h"
#include <stdarg.h>

/**
 * spec_c - function for c specifier
 * @arg_ptr: pointer to argument list
 *
 * Return: number of bytes printed
 */

int spec_c(va_list arg_ptr)
{
	char character = (char)va_arg(arg_ptr, int);

	return (print_char(character));
}

int spec_s(va_list arg_ptr)
{
	char *string = va_arg(arg_ptr, char *);

	return (print_string(string));
}

int spec_percent()
{
	return (print_char('%'));
}

int spec_di(va_list arg_ptr)
{
	long number = va_arg(arg_ptr, int);

	return (print_base_digit(number, 10));
}

int spec_b(va_list arg_ptr)
{
	long number = va_arg(arg_ptr, int);

	return (print_base_digit(number, 2));
}
