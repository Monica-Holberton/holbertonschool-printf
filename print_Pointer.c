#include "main.h"
#include <stdarg.h>

/**
 * print_pointer - prints a memory address in hexadecimal with "0x" prefix
 * @args: va_list
 * @count: pointer to count of characters printed
 */
void print_pointer(va_list args, int *count)
{
    void *ptr = va_arg(args, void *);
    unsigned long addr = (unsigned long)ptr;

    if (!ptr)
    {
        char *null_str = "(nil)";
        while (*null_str)
            print_char(*null_str++, count);
        return;
    }

    print_char('0', count);
    print_char('x', count);
    print_hex(addr, count, 0); /*lowercase hex*/
}
