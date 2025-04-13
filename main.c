#include "main.h"
#include <stdio.h>
#include <limits.h>

/**
 * main - Entry point for testing _printf
 * Description: Tests basic specifiers and edge cases
 * Return: Always 0
 */
int main(void)
{
    int len1, len2;

    /* Basic specifiers 'S' + 'C'*/
    len1 = _printf("Hello %s! Char: %c Percent: %%\n", "Monica", 'M');
    len2 = printf("Hello %s! Char: %c Percent: %%\n", "Monica", 'M');

    _printf("My length: %d\n", len1);
    printf("Real length: %d\n", len2);

    /* Binary and Octal */
    _printf("Binary of 98: %b\n", 98);
    _printf("Octal of 98: %o\n", 98);

    /* Unsigned and Hex */
    _printf("Unsigned: %u\n", 123456789);
    _printf("Hex (lowercase): %x\n", 48879);
    _printf("Hex (UPPERCASE): %X\n", 48879);

    /* Edge cases */
    _printf("%d\n", 0);
    _printf("%d\n", INT_MIN);
    _printf("%d\n", INT_MAX);

    return (0);
}

