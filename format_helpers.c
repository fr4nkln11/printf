#include "main.h"

/**
 * print_char - print a character
 * @character: character to be printed
 *
 * Return: 1
 */

int print_char(char character)
{
	if (character != '\0')
	{
		return (write(1, &character, 1));
	}
	else
	{
		return (0);
	}
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

