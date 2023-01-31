#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_char - function that writes a char on the terminal
 *
 * @arg: the argument list
 *
 * Return: return 1, otherwise -1
 */

int print_char(va_list arg)
{
	int c = va_arg(arg, int);

	if (c)
	{
		write(1, &c, 1);
		return (1);
	}

	return (-1);
}

/**
 * print_percetange - function that writes a percetange symbol on the terminal
 *
 * @arg: the argument list
 *
 * Return: if success 1, otherwise -1
 */

int print_percetange(va_list arg)
{
	char c = '%';

	if (c && arg)
	{
		write(1, &c, 1);
		return (1);
	}

	return (-1);
}

/**
 * print_string - function that writes a string on the terminal
 *
 * @arg: the argument list
 *
 * Return: the length of the string
 */

int print_string(va_list arg)
{
	int i;
	char *s = va_arg(arg, char *);

	if (!s)
		s = "(null)";

	for (i = 0; s[i] != 0; i++)
		write(1, &(s[i]), 1);

	return (i);
}
