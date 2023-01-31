#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_number - function that prints a number
 *
 * @arg: the argument list
 *
 * Return: the length of the number
 */

int print_number(va_list arg)
{
	int i = va_arg(arg, int);
	int number, n = 1;
	int length = 0;
	char minus = '-';

	if (i < 0)
	{
		write(1, &(minus), 1);
		length++;
		i *= -1;
	}

	while ((i / n) > 10)
		n *= 10;

	number = (i / n) + 48;
	write(1, &(number), 1);
	length++;

	while ((i - (i / n)) != 0)
	{
		i -= n * (i / n);
		n = n / 10;

		number = (i / n) + 48;
		write(1, &(number), 1);
		length++;
	}

	return (length);
}
