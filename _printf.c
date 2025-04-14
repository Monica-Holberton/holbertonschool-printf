#include "main.h"
#include <stdarg.h>

/**
 * _printf - Custom printf function that handles multiple specifiers
 * @format: The format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    int precision = -1; /* Precision default unset */
    char *str;
    char ch;
    int num;

    if (!format)
        return (-1);

    va_start(args, format);

    while (*format)
    {
        if (*format == '%' && *(format + 1))
        {
            format++;

            /* Handle precision if exists */
            if (*format == '.')
            {
                format++;
                format += get_precision(format, &precision);
            }

            /* Handle format specifier */
            switch (*format)
            {
                case 'c':  /* Character */
                    ch = va_arg(args, int);
                    print_char(ch, &count);
                    break;

                case 's':  /* String */
                    str = va_arg(args, char *);
                    if (!str)
                        str = "(null)";
                    while (*str)
                        print_char(*str++, &count);
                    break;
                case 'r':  /* Reversed String */
                    str = va_arg(args, char *);
                    if (!str)
                        str = "(null)";
                    print_reverse(str, &count);
                    break;

                case '%':  /* Percent */
                    print_char('%', &count);
                    break;

                case 'd':  /* Decimal */
                case 'i':  /* Integer */
                    num = va_arg(args, int);
                    if (precision >= 0)
                        print_number_precision(num, precision, &count);
                    else
                        print_number(num, &count);
                    break;

                case 'b':  /* Binary */
                    print_binary(va_arg(args, unsigned int), &count);
                    break;

                case 'u':  /* Unsigned Decimal */
                    print_unsigned(va_arg(args, unsigned int), &count);
                    break;

                case 'o':  /* Octal */
                    print_octal(va_arg(args, unsigned int), &count);
                    break;

                case 'x':  /* Hex lowercase */
                    print_hex(va_arg(args, unsigned int), &count);
                    break;

                case 'X':  /* Hex uppercase */
                    print_upper_hex(va_arg(args, unsigned int), &count);
                    break;
                case 'h':
                    print_length(va_arg(args, int), 'h', format, &count);
                    break;
                default:  /* Unknown specifier, print as is */
                    print_char('%', &count);
                    print_char(*format, &count);
                    break;
            }
        }
        else if (*format == '%' && *(format + 1) == '\0')
        {
            va_end(args);
            return (-1); /* Lone '%' at end */
        }
        else
        {
            print_char(*format, &count);
        }

        format++;
        precision = -1; /* Reset precision for next specifier */
    }

    va_end(args);
    flush_buffer();
    return (count);
}