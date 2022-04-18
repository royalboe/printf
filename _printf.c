#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <stddef.h>
#include <stdint.h>
/**
 * _printf - recreates the printf function
 * @format: string with format specifier
 * Return: number of characters printed
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
