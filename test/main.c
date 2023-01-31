#include <stdio.h>
#include "main.h"

int main(void)
{
	char *str = "Hello Jeffer!";
	_printf("%s\n", str);

	printf("%zj\n");
	_printf("%zj\n");

	printf("%jz\n");
	_printf("%jz\n");

	return (0);
}
