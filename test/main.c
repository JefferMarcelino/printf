#include <stdio.h>
#include "main.h"

int main(void)
{
	int len, len2;

	char *str = "Hello Jeffer!";
	_printf("%s\n", str);

	len = _printf("This is a number: %d\n", -123456);
	len2 = printf("This is a number: %d\n", -123456);
	_printf("Len: [%d, %i]\n", len, len2);

	len = _printf("This is a number: %d\n", 123456);
	len2 = printf("This is a number: %d\n", 123456);
	_printf("Len: [%d, %i]\n", len, len2);

	len = _printf("This is a number: %d\n", 0);
	len2 = printf("This is a number: %d\n", 0);
	_printf("Len: [%d, %i]\n", len, len2);

	len = _printf("This is a number: %d\n", 2006);
	len2 = printf("This is a number: %d\n", 2006);
	_printf("Len: [%d, %i]\n", len, len2);

	return (0);
}
