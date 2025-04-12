#include "main.h"
#include <stdio.h>

/**
 * main - Entry point
 *_printf - 
 * Return: Always 0
 */
int main(void)
{
    _printf(" %o\n", 80);       /*print: Binary of 98 is: 1100010 */

    int len1 = _printf("Binary of 98: %b\n", 98);
    int len2 = _printf("Octal of 98: %o\n", 98);
    _printf("Length: %d and %d\n", len1, len2);
    return (0);
}

