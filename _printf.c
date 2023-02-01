#include <unistd.h>
#include "main.h"

/**
 * _printf - function that does the same thing as printf
 *
 * @format: the string to be printed formated
 *
 * Return: the length of the string
 */

int _printf(const char *format, ...)
{
	int i, length = 0;
	int (*func_print)(va_list arg);
	va_list args;

	if (format == 0)
		return (-1);
	va_start(args, format);
	for (i = 0; format && format[i] != 0; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 0)
				return (-1);

			if (format[i + 1] == ' ')
			{
				i++;
				write(1, &(format[i]), 1);
				length++;
			}

			func_print = get_print_func(&(format[i + 1]));
			if (func_print)
			{
				length += func_print(args);
				i++;
			}
			else
			{
				write(1, &(format[i + 2]), 1);
				length++;
			}
		}
		else
		{
			write(1, &(format[i]), 1);
			length++;
		}
	}
	va_end(args);
	return (length);
}
