#include "main.h"

/**
 * print_octal - print numbers in base 8
 * @n: number to print
 * Return: @count, number or chars printed.
 */
int print_octal(unsigned int n)
{
	unsigned int u, o, x, X, l, h;
	int count = 0;

	o = n;
	x = 1;
	for (u = 1 ; o > 7 ; u++)
	{
		o = o / 8;
		x = x * 8;
		count++;
	}
	for (h = 1; h <= a; h++)
	{
		X = n / x;
		n = n % x;
		x = x / 8;
		_putchar(X + '0');
		count++;
	}
	return (count);
}
