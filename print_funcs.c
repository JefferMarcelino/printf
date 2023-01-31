#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_char - function that writes a char on the terminal
 *
 * @arg: the char
 *
 * Return: always return 1
 */

int print_char(va_list arg)
{
	int c = va_arg(arg, int);

	write(1, &c, 1);

	return (1);
}


/**
 * print_string - function that writes a string on the terminal
 *
 * @arg: the string
 *
 * Return: the length of the string
 */

int print_string(va_list arg)
{
	int i;
	char *s = va_arg(arg, char *);

	for (i = 0; s[i] != 0; i++)
		write(1, &(s[i]), 1);

	return (i);
}
