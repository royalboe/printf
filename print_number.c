#include "main.h"

/**
 * print_number - printing numbers with putchar (Thanks Daniel "El profe")
 * @n: number to print
 * Return: no return.
 */
int print_number(int n)
{
        unsigned int a, b, c, d, f;
        int count = 0;

        if (n < 0)
        {
                _putchar('-');
                n = n * -1;
                count++;
        }
        b = n;
        c = 1;
        for (a = 1 ; b > 9 ; a++)
        {
                b = b / 10;
                c = c * 10;
        }
        for (f = 1; f <= a; f++)
        {
                d = n / c;
                n = n % c;
                c = c / 10;
                _putchar(d + '0');
                count++;
        }
        return (count);
}
