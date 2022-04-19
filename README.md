# C - printf

## Description
Create an simple exact replica of the printf function found in the C programming language. Using Variadic functions, structs, and multiple helper functions, the program we created will be able display inputed characters, strings, integers, and decimals (base 10). Whatever format specifier you use with our `_prinf` function, should display the same results when used by the actual printf function. This project is to show an alternative method of creating your very own simple printf function in the C programming language.

If successfully compiled and executed, the function should return the number of characters printed (excluding the null byte used to end output to strings). And if it fails, then the function should return a `(-1)` upon error and `"(null)"` if the string argument takes in NULL. If the format specifier is unkown, then the output would print out the format specifier as a string.

The code was made to handle all the format specifiers, but because of the simplicity of our code, we only used 5 so far. In the future, we will update the printf repository to handle more format specifiers.

### Prototype
`int _printf(const char *format, ...)`

- Returns: the number of characters printed (excluding the null byte used to end output to strings).
- Write output to stdout, the standard output stream.
- `format` is a character string. The format string is composed of zero or more directives. See `man 3 printf` for more detail.
### File Usage
File Name | Description

The _printf program will replicate the effects of the listed % format specifiers as when used with printf.

Function name | Description | Format Specifier
--- | --- | ---
`_print_char` | Prints a single character | `%c`
`_print_string` | Prints a string of characters | `%s`
`_print_percent` | Prints a % | `%%`
`_print_int` | Prints an integer in base 10| `%d` & `%i`
`_print_reverse` | Prints the string in reverse | `r`
`_print_rot13` | Converts the string into Rot13 | `R`
`_print_binary` | Prints the binary form of the integer | `b`
`_print_unsigned` | Prints an unsigned integer | `u`
`_print_octal` | Prints and octal number | `o`
`_print_hex_l` | Prints the lower case hexidecimal number | `x`
`_print_hex_u` | Prints the upper case hexidecimal number | `X`
### Compilation

Our code can be compiled in either example
```
$ gcc -Wall -Werror -Wextra -pedantic *.c
```
or (if you want to test for unknown format specifiers)

```
$ gcc -Wall -Werror -Wextra -pedantic -Wno-format *.c
```
## Testing the Program

### The main.c File Test
You'll make a main.c file to test the program, in order to see if the custom _printf function works exactly like how regular printf manages to display the number of characters printed.
The main.c file should contain the code displayed below. (Feel free to change the code inside main.c to test for any other test cases not currently displayed.)
```
Timmy@ubuntu:~/c/printf$ cat main.c
#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
    return (0);
}
```
### Output Check
Your output should after compiling the program should look something like what's displayed below.
```
Timmy@ubuntu:~/c/printf$ gcc -Wall -Wextra -Werror -pedantic -Wno-format *.c
Timmy@ubuntu:~/c/printf$ ./printf
Let's try to printf a simple sentence.
Let's try to printf a simple sentence.
Length:[39, 39]
Length:[39, 39]
Negative:[-762534]
Negative:[-762534]
Unsigned:[2147484671]
Unsigned:[2147484671]
Unsigned octal:[20000001777]
Unsigned octal:[20000001777]
Unsigned hexadecimal:[800003ff, 800003FF]
Unsigned hexadecimal:[800003ff, 800003FF]
Character:[H]
Character:[H]
String:[I am a string !]
String:[I am a string !]
Address:[0x7ffe637541f0]
Address:[0x7ffe637541f0]
Percent:[%]
Percent:[%]
Len:[12]
Len:[12]
Unknown:[%r]
Unknown:[%r]
Timmy@ubuntu:~/c/printf$
```
### Bugs
It should be noted that our code does not handle the following conditions:
* You don’t have to reproduce the buffer handling of the C library printf function.
* You don’t have to handle the flag characters.
* You don’t have to handle field width.
* You don’t have to handle precision.
* You don’t have to handle the length modifiers.
### About
All files were created and compiled on `Ubuntu 14.04.4 LTS` using `GCC 4.8.4`
## Authors
