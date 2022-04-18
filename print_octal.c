#include "main.h"

/**
 * print_octal - print numbers in base 8
 * @n: number to print
 * Return: @count, number or chars printed.
 */
int print_octal(unsigned int n)
{
	unsigned int a, b, c, d, f;
	int count = 0;

	b = n;
	c = 1;
	for (a = 1 ; b > 7 ; a++)
	{
		b = b / 8;
		c = c * 8;
		count++;
	}
	for (f = 1; f <= a; f++)
	{
		d = n / c;
		n = n % c;
		c = c / 8;
		_putchar(d + '0');
		count++;
	}
	return (count);
}
