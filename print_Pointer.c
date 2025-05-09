#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>

/**
 * print_pointer - Prints a pointer address in hexadecimal format.
 * @args: List of arguments
 * @count: Pointer to the character count
 */
void print_pointer(va_list args, int *count)
{
    void *ptr = va_arg(args, void*);
    unsigned long addr = (unsigned long)ptr;
    char hex_digits[] = "0123456789abcdef";
    char hex[20];
    int i = 0;

    if (ptr == NULL)
    {
        add_to_buffer('(', count);
        add_to_buffer('n', count);
        add_to_buffer('i', count);
        add_to_buffer('l', count);
        add_to_buffer(')', count);
        return;
    }

    add_to_buffer('0', count);
    add_to_buffer('x', count);

    while (addr > 0)
    {
        hex[i++] = hex_digits[addr % 16];
        addr /= 16;
    }

    while (i--)
    {
        add_to_buffer(hex[i], count);
    }
}
