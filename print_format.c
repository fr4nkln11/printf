#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int print_char(char character)
{
	return (write(1, &character, 1));
}

int print_string(char *string)
{
	int char_count;

	char_count = 0;

	while (*string != '\0')
	{
		char_count += print_char(*string);
		string++;
	}

	return (char_count);
}

int print_format(char specifier, va_list arg_ptr)
{
	int char_count;

	char_count = 0;

	switch (specifier)
	{
		case 'c':
			char_count += print_char((char)va_arg(arg_ptr, int));
			break;

		case 's':
			char_count += print_string(va_arg(arg_ptr, char *));
			break;

		default:
			char_count += write(1, &specifier, 1);
			break;
	}

	return (char_count);
}
