#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


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


#endif
