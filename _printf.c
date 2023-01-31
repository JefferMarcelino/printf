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
		{"s", print_string}
	};

	va_start(args, format);

	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%' && (format[i + 1] != '%' || format[i + 1] != 0))
		{
			for (j = 0; (j < 2) && (format[i + 1] != *(ops[j].symbol)); j++)
				;

			if (j < 2)
			{
				length += ops[j].func(args);
				i++;
			}
			else
			{
				write(1, &(format[i]), 1);

				if (format[i] == '%' && format[i + 1] == '%')
					i++;
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
