#include "main.h"

/**
 * print_format - select the correct specifier and print
 * @specifier: the format specifier to check
 * @arg_ptr: argument pointer
 *
 * Return: the number of characters printed
 */

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

		case '%':
			char_count += write(1, "%", 1);
			break;

		default:
			char_count += write(1, "%", 1);
			char_count += write(1, &specifier, 1);
			break;
	}

	return (char_count);
}
