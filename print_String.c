#include "main.h"
#include <stdarg.h>

/**
 * print_string_non_printable - prints a string, non-printables in hex
 * @args: va_list
 * @count: pointer to char count
 */
void print_string(va_list args, int *count)
{
    char *str = va_arg(args, char *);
    int i;

    if (!str)
        str = "(null)";

    for (i = 0; str[i]; i++)
    {
        if (str[i] < 32 || str[i] >= 127)
        {
            print_char('\\', count);
            print_char('x', count);
            if (str[i] < 16)
                print_char('0', count);
            print_hex(str[i], count, 1); /* uppercase hex */
        }
        else
            print_char(str[i], count);
    }
}
