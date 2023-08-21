#include "main.h"

/**
 * print_char - print a character
 * @character: character to be printed
 *
 * Return: 1
 */

int print_char(char character)
{
	return (write(1, &character, 1));
}

/**
 * print_string - print a string of characters
 * @string: pointer to string
 *
 * Return: number of characters printed
 */

int print_string(char *string)
{
	int char_count;

	char_count = 0;

	if (string != NULL)
	{
		while (*string != '\0')
		{
			char_count += print_char(*string);
			string++;
		}
	}
	else
	{
		char_count += print_string("(null)");
	}

	return (char_count);
}

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
