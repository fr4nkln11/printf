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
	int char_count;
	va_list arg_ptr;

	char_count = 0;

	if (format[0] == '\0')
	{
		return (0);
	}

	if ((format[0] == '%' && format[1] == '\0')
			|| (format[0] == '%' && format[1] == ' ' && format[2] == '\0'))
	{
		return (-1);
	}

	if (format != NULL)
	{
		va_start(arg_ptr, format);
		while (*format != '\0')
		{
			/* if the character pointed to is a % */
			if (*format == '%')
			{
				char_count += print_format(*(++format), arg_ptr);
			}
			else
			{
				char_count += write(1, format, 1);
			}
			format++;
		}
		va_end(arg_ptr);
	}
	else
	{
		return (-1);
	}

	return (char_count);
}
