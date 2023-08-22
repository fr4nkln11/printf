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
 * print_base_digit - print a string of digits for a specific base
 * @number: the number to be printed
 * @base: the base for the number to be printed
 *
 * Return: number of digits printed
 */

int print_base_digit(long number, int base)
{
	int digit_count;
	char *digits;

	digits = "0123456789";

	if (number < 0)
	{
		return (write(1, "-", 1) + print_base_digit(-number, base));
	}
	else if (number < base)
	{
		return (print_char(digits[number]));
	}
	else
	{
		digit_count = print_base_digit(number / base, base);
		return (digit_count + print_base_digit(number % base, base));
	}
}
