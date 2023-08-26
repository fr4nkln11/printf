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
	int char_count, spec_index;
	spec_t specs[] = {
		{'c', spec_c},
		{'s', spec_s},
		{'d', spec_di},
		{'i', spec_di},
		{'b', spec_b},
		{'\0', NULL}
	};

	char_count = 0;
	spec_index = 0;

	while (specs[spec_index].specifier != '\0')
	{
		if (specifier == specs[spec_index].specifier)
		{
			char_count += specs[spec_index].specifier_function(arg_ptr);
			break;
		}
		spec_index++;
	}

	if (specifier == '%')
	{
		char_count += print_char('%');
	}
	else if (char_count == 0)
	{
		char_count += print_char('%');
		char_count += print_char(specifier);
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
