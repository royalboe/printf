#include "main.h"

/**
 * *rot13 - encoding to ROT13
 * @s: string to work
 * Return: the result.
 */
int rot13(char *s)
{
	int a, b, count = 0;
	char first[52] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char second[52] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	a = 0;
	while (s[a] != 0)
	{
		if ((s[a] >= 'A' && s[a] <= 'Z') || (s[a] >= 'a' && s[a] <= 'z'))
		{
			for (b = 0; b < 52; b++)
			{
				if (s[a] == first[b])
				{
					count += _putchar(second[b]);
				}
			}
		} else
			count += _putchar(s[a]);
		a++;
	}
	return (count);
}
