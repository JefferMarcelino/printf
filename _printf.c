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
	int i, j, length = 0;
	va_list args;
	print_options ops[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percetange},
		{NULL, NULL}
	};

	if (format == 0)
		return (-1);

	va_start(args, format);
	for (i = 0; format && format[i] != 0; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; (j < 3) && (format[i + 1] != *(ops[j].symbol)); j++)
				;

			if (j < 3)
			{
				length += ops[j].func(args);
				i++;
			}
			else
			{
				write(1, &(format[i]), 1);
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
