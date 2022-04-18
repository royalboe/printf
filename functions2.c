#include "main.h"
/**
 * print_bi - convert dec to decimal
 *@n:number decimal
 *Return: times of number print
 */
int print_bi(unsigned int n)
{
	unsigned int a, b, c, d, f;
	int count = 0;

	b = n;
	c = 1;
	for (a = 1 ; b > 1 ; a++)
	{
		b = b / 2;
		c = c * 2;
	}
	for (f = 1; f <= a; f++)
	{
		d = n / c;
		n = n % c;
		c = c / 2;
		_putchar(d + '0');
		count++;
	}
	return (count);
}

/**
 * print_hexalow - convert unsigned int in hexadecimal
 *@n: unsigned int
 * Return: numer times print
 */
int print_hexalow(unsigned int n)
{
	int i, j, remainder, count = 0;
	unsigned int num_copy = n;
	char *hexadecimal;

	if (n == 0)
		return (_putchar('0'));
	while (num_copy != 0)
	{
		num_copy /= 16;
		count++;
	}
	hexadecimal = malloc(count);
	for (i = 0; n != 0; i++)
	{
		remainder = 0;
		remainder = n % 16;
		if (remainder < 10)
		{
			hexadecimal[i] = remainder + '0';
		}
		else
		{
			hexadecimal[i] = remainder + 'W';
		}
		n /= 16;
	}
	for (j = i - 1; j >= 0; j--)
		_putchar(hexadecimal[j]);
	free(hexadecimal);
	return (count);
}

/**
 * print_hexaup - Print number in hexadecimal with upper numbers
 *@n: unsigned int
 * Return: numer times print
 */
int print_hexaup(unsigned int n)
{
	int i, j, remainder, count = 0;
	unsigned int num_copy = n;
	char *hexadecimal;

	if (n == 0)
		return (_putchar('0'));
	while (num_copy != 0)
	{
		num_copy /= 16;
		count++;
	}
	hexadecimal = malloc(count);
	for (i = 0; n != 0; i++)
	{
		remainder = 0;
		remainder = n % 16;
		if (remainder < 10)
		{
			hexadecimal[i] = remainder + '0';
		}
		else
		{
			hexadecimal[i] = remainder + '7';
		}
		n /= 16;
	}
	for (j = i - 1; j >= 0; j--)
		_putchar(hexadecimal[j]);

	free(hexadecimal);
	return (count);
}


