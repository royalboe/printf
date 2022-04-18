#include "main.h"

/**
 * print_unsig - print unsigned numbers
 * @n: number to print
 * Return: @count, number or chars printed.
 */
int print_unsig(unsigned int n)
{
	int count = 0;
	unsigned int num_copy = n;

	if (n == 0)
		count = 1;
	while (num_copy != 0)
	{
		num_copy = num_copy / 10;
		count++;
	}
	if (n >= 10)
		print_unsig(n / 10);
	_putchar (n % 10 + '0');
	return (count);
}
