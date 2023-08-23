#include "main.h"
#include <stdarg.h>

/**
 * print_format - select the correct specifier and print
 * @specifier: the format specifier to check
 * @arg_ptr: pointer to argument list
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

		case 'd':
		case 'i':
			char_count += print_base_digit(va_arg(arg_ptr, int), 10);
			break;

		case 'b':
			char_count += print_base_digit(va_arg(arg_ptr, int), 2);
			break;

		default:
			char_count += write(1, "%", 1);
			char_count += write(1, &specifier, 1);
			break;
	}

	return (char_count);
}

/**
 * scan_format - this function scans through the format string,
 * checks for format specifiers and prints regular characters
 * @format: format string
 * @arg_ptr: pointer to argument list
 *
 * Return: the number of characters printed
 */

int scan_format(const char *format, va_list arg_ptr)
{
	int char_count;

	char_count = 0;

		while (*format != '\0')
		{
			/* if the character pointed to is a % */
			if (*format == '%')
			{
				if (*(format + 1) == '\0')
				{
					return (-1);
				}
				else
				{
					char_count += print_format(*(++format), arg_ptr);
				}
			}
			else
			{
				char_count += write(1, format, 1);
			}
			format++;
		}

	return (char_count);
}
