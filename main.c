#include "main.h"
#include <stdio.h>

/**
 * main - Entry point
 *_printf - 
 * Return: Always 0
 */
int main(void)
{

    _printf("%d\n",0);

_printf("%.5d\n", 42);     // Should print: 00042
_printf("%.3s\n", "Hello"); // Should print: Hel
_printf("%.2d\n", -7);      // Should print: -07
    
    return (0);
}


