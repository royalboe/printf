#ifndef our_printf
#define our_printf
#include <stdio.h>
#include <stdarg.h>
/**
 * struct specifier - struct specifier
 * @valid: the valid character.
 * @f: the functions associated.
 *
 */
typedef struct specifier
{
	char *valid;
	int (*f)(va_list);
} spec;

int _putchar(char c);
int print_number(int n);
int _printf(const char *format, ...);
int print_octal(unsigned int n);
int print_unsig(unsigned int n);
int print_hexaup(unsigned int n);
int print_hexalow(unsigned int n);
int print_bi(unsigned int n);
int _printstring(char *s);
int rot13(char *point);
int print_rev(char *);
int print_hl(uintptr_t n);
int _withformat4(char c, int count, va_list valist);
int _withformat3(char c, int count, va_list valist);
int _withformat2(char c, int count, va_list valist);
int _withformat(char c, int count, va_list valist);
#endif
