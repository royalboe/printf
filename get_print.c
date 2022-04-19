#include "main.h"

/**
 * get_print - Matches specifier and returns count
 * @format: a character string
 * @argument: Specifiers being checked against
 * @ap: Action pointer
 *
 * Return:  the number of characters printed
 */
int get_print(const char *format, print_type argument[], va_list ap)
{
	int i, j;
	int count = 0;

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] != '%')
		{
			count += _putchar(format[i]);
			continue;
		}
		for (j = 0; argument[j].parameter; j++)
		{
			if (*argument[j].parameter == format[i + 1])
			{
				count += argument[j].f(ap);
				break;
			}
		}
		i++;
		if (!argument[j].parameter)
		{
			count += _putchar('%');
			count += _putchar(format[i]);
		}
	}
	return (count);
}
