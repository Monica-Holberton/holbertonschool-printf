#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

/**
 * _printf - Custom implementation of printf function
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    int i = 0;

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%')  /* Handle format specifiers */
        {
            i++;

            /* Check for length modifiers and specifiers */
            if (format[i] == 'd' || format[i] == 'i') /* Integer specifier */
                print_number(va_arg(args, int), &count);
                else if (format[i] == 'c') /* Character specifier */
                {
                    char ch = va_arg(args, int);
                    print_char(ch, &count);
                }
                else if (format[i] == 's') /* String specifier */
                {
                    char *str = va_arg(args, char *);
                    while (*str)
                        print_char(*str++, &count);
                }
                else if (format[i] == '%') /* Percent sign specifier */
                {
                    print_char('%', &count);
                }
            else if (format[i] == 'b') /* Binary specifier */
                print_binary(va_arg(args, unsigned int), &count);
            else if (format[i] == 'u') /* Unsigned specifier */
                print_unsigned(va_arg(args, unsigned int), &count);
            else if (format[i] == 'o') /* Octal specifier */
                print_octal(va_arg(args, unsigned int), &count);
            else if (format[i] == 'x') /* Lowercase hex specifier */
                print_hex(va_arg(args, unsigned int), &count, 0); /* lowercase hex */
            else if (format[i] == 'X') /* Uppercase hex specifier */
                print_hex(va_arg(args, unsigned int), &count, 1); /* UPPERCASE hex */
            else if (format[i] == 'r') /* Reversed string specifier */
                print_reverse(args, &count);
            else if (format[i] == 'S') /* Custom non-printable characters specifier */
                print_string(args, &count);
            else if (format[i] == 'p') /* Pointer address specifier */
                print_pointer(va_arg(args, void *), &count);
            else
            {
                print_char('%', &count);  /* Handle unknown specifier by printing % */
                print_char(format[i], &count);
            }
        }
        else  /* Regular character */
        {
            print_char(format[i], &count);
        }
        i++;
    }

    flush_buffer();
    va_end(args);

    return count;
}
