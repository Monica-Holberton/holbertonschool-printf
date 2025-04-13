#include "main.h"
#include <stdio.h>
#include <limits.h>

/**
 * main - Entry point for testing _printf
 * Description: Tests _printf with basic, custom, and edge-case format specifiers
 * Return: Always 0
 */
int main(void)
{
	int len1, len2;

	/* Basic specifiers: %s, %c, %% */
	len1 = _printf("Hello %s! Char: %c Percent: %%\n", "Monica", 'M');
	len2 = printf("Hello %s! Char: %c Percent: %%\n", "Monica", 'M');
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

	return (0);
}
