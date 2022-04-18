#include "main.h"
#include <stdarg.h>
#include <stdint.h>
/**
 * _withformat4 - prints depending the format
 * @c: the format sent by the main
 * @count: characters printed;
 * @valist: va_list args
 * Return: @count the number of characters printed
 */
int _withformat4(char c, int count, va_list valist)
{
	uintptr_t p;
	void *pi;


	switch (c)
	{
	case 'p':
		pi = va_arg(valist, void *);
		p = (uintptr_t)pi;

		if (pi == NULL)
		{
			_printf("(nil)");
			count += 5;
		}
		else
		{
			_putchar('0');
			_putchar('x');
			count += 2;
			count += print_hl(p);
		}
		break;
	default:
		count += 2;
		_putchar('%');
		_putchar(c);
	}
	return (count);
}

/**
 * _withformat3 - prints depending the format
 * @c: the format sent by the main
 * @count: characters printed;
 * @valist: va_list args
 * Return: @count the number of characters printed
 */
int _withformat3(char c, int count, va_list valist)
{
	char *s;
	int i;
	char si[6] = "(null)";

	switch (c)
	{
	case 'R':
		s = va_arg(valist, char *);
		if (!s)
		{
			for (i = 0; si[i]; i++, count++)
				_putchar(si[i]);
		}
		else
			count += rot13(s);
		break;
	case 'r':
		s = va_arg(valist, char *);
		if (!s)
		{
			for (i = 0; si[i]; i++, count++)
				_putchar(si[i]);
		}
		else
			count += print_rev(s);
		break;
		default:
			count = _withformat4(c, count, valist);
	}
	return (count);
}
/**
 * _withformat2 - prints depending the format
 * @c: the format sent by the main
 * @count: characters printed;
 * @valist: va_list args
 * Return: @count the number of characters printed
 */
int _withformat2(char c, int count, va_list valist)
{
	unsigned int k;

	switch (c)
	{
		case 'b':
			k = va_arg(valist, unsigned int);

			count += print_bi(k);
			break;
		case 'o':
			k = va_arg(valist, unsigned int);

			count += print_octal(k);
			break;
		case 'x':
			k = va_arg(valist, unsigned int);

			count += print_hexalow(k);
			break;
		case 'X':
			k = va_arg(valist, unsigned int);

			count += print_hexaup(k);
			break;
		case 'u':
			k = va_arg(valist, unsigned int);

			count += print_unsig(k);
			break;
		default:
			count = _withformat3(c, count, valist);
	}
	return (count);
}


/**
 * _withformat - prints depending the format
 * @c: the format sent by the main
 * @count: characters printed;
 * @valist: va_list args
 * Return: @count the number of characters printed
 */

int _withformat(char c, int count, va_list valist)
{
	int j, i;
	char *s;
	char si[6] = "(null)";

	switch (c)
	{
		case 'c':
			j = va_arg(valist, int);
			count += _putchar(j);
			break;
		case 's':
			s = va_arg(valist, char *);
			if (!s)
			{
				for (i = 0; si[i]; i++, count++)
					_putchar(si[i]);
			}
			else
				count += _printstring(s);
			break;
		case '%':
			count += _putchar('%');
			break;
		case 'i':
		case 'd':
			j = va_arg(valist, int);

			if (!j)
			{
				count++;
				_putchar('0');
			} else
				count += print_number(j);
			break;
		default:
			count = _withformat2(c, count, valist);
	}
	return (count);
}

/**
 * _printf - Fuction that prints to the std output
 * @format: list of parameters passed
 * Return: @count the number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0;
	int count = 0;
	va_list valist;

	va_start(valist, format);

	if (!format)
		return (-1);
	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
		{
			count++;
			_putchar(format[i]);
		}
		else if (format[i + 1])
		{
			i++;
			count = _withformat(format[i], count, valist);
		}
		else
			return (-1);
	}
	va_end(valist);
	return (count);
}
