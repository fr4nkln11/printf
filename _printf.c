#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - a function that produces output according to a format.
 * @format: a character string.
 * The format string is composed of zero or more directives.
 *
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */

int _printf(const char *format, ...)
{
	int char_count, index;
	va_list arg_ptr;

	char_count = 0;

	if (format != NULL)
	{
		va_start(arg_ptr, format);
		index = 0;

		while (*(format + index) != '\0')
		{
			char_count += write(1, (format + index), 1);
			index++;
		}

	}
	return (char_count);
}
