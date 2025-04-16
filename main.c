#include "main.h"
#include <stdio.h>
#include <limits.h>

/**
 * main - Entry point for testing _printf
 *
 * Return: Always 0
 */
int main(void)
{
    int len1, len2;
    unsigned int ui;
    long int long_num = 1234567890;

    /* Basic string and char prints */
    _printf("Line 1\nLine 2\n");
    _printf("Let's print a simple sentence.\n");
    _printf("%c\n", 'S');
    _printf("A char inside a sentence: %c. Did it work?\n", 'F');
    _printf("Let's see if the cast is correctly done: %c. Did it work?\n", 48);
    _printf("%s", "This sentence is retrieved from va_args!\n");
    _printf("Complete the sentence: You %s nothing, Jon Snow.\n", "know");
    _printf("%%\n");
    _printf("Should print a single percent sign: %%\n");
    _printf("%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');

    /* Compare lengths */
    len1 = _printf("Hello %s!\n", "Monica");
    len2 = printf("Hello %s!\n", "Monica");
    _printf("My length: %d\n", len1);
    printf("Real length: %d\n", len2);

    /* Binary and Octal */
    _printf("Binary of 98: %b\n", 98);
    _printf("Octal of 98: %o\n", 98);

    /* Unsigned and Hexadecimal */
    _printf("Unsigned: %u\n", 123456789);
    _printf("Hex (lowercase): %x\n", 48879);
    _printf("Hex (UPPERCASE): %X\n", 48879);

    /* Decimal Integers and edge values */
    _printf("Zero: %d\n", 0);
    _printf("INT_MIN: %d\n", INT_MIN);
    _printf("INT_MAX: %d\n", INT_MAX);

    /* Precision for Integers and Strings */
    _printf("Precision (5) for 42: %.5d\n", 42);
    _printf("Precision (3) for \"Hello\": %.3s\n", "Hello");
    _printf("Precision (2) for -7: %.2d\n", -7);

    /* Combining with other specifiers */
    _printf("Number: %d\n", 1024);
    _printf("Reversed: %r\n", "custom");
    _printf("Char: %c\n", 'Z');
    _printf("Long: %ld\n", long_num);

    /* Segmentation fault */
    _printf("Segmentation fault example: %r\n", "this should cause an error");

    return (0);
}

