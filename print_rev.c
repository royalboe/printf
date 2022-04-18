#include "main.h"
/**
 *print_rev - print string in reverse
 *@str: string pointer
 *Return: counter
 */
int print_rev(char *str)
{
	char *z = str;
	int i;
	int count1 = 0;
	int count = 0;

	while (*str != '\0')
	{
		str++;
		count1++;
	}

	i = count1 - 1;
	while (i >= 0)
	{
		_putchar(*(z + i));
		i--;
		count++;
	}

	return (count);
}
