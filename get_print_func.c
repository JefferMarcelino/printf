#include <stdarg.h>
#include <stddef.h>
#include "main.h"

/**
 * get_print_func - function that selects the right print function
 *
 * @symbol: the symbol used to select the right print function
 *
 * Return: the pointer to the print function, otherwise 0
 */

int (*get_print_func(const char *symbol))(va_list arg)
{
	int i;
	print_options options[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percetange},
		{NULL, NULL}
	};

	for (i = 0; (i < 3) && (*symbol != *(options[i].symbol)); i++)
		;

	if (i < 3)
		return (options[i].func);

	return (0);
}
