#ifndef _MAIN_

#define _MAIN_
#include <stdarg.h>

int _printf(const char *format, ...);
int print_char(va_list arg);
int print_percetange(va_list arg);
int print_string(va_list arg);
int print_number(va_list arg);
int (*get_print_func(const char *symbol))(va_list arg);

/**
 * struct print - A new struct type defining our print
 *
 * @symbol: Our symbol representing the data type
 * @func: a function pointer that prints
 *        a data type according to the symbol
 */

typedef struct print
{
	char *symbol;
	int (*func)(va_list arg);
} print_options;

#endif
