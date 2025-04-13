#include "main.h"
#include <stdarg.h>

/**
 * _printf - Custom printf that handles basic specifiers with precision
 * @format: The format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    int precision;
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

            /* Handle precision */
            if (*format == '.')
            {
                format++;
                format += get_precision(format, &precision);

                if (*format == 'd' || *format == 'i')
                {
                    num = va_arg(args, int);
                    print_number_precision(num, precision, &count);
                }
                /* Add handling for %.s (if needed)*/
            }
            else
            {
                switch (*format)
                {
                    case 'c':  /* Specifier '%c' */
                        ch = va_arg(args, int);
                        print_char(ch, &count);
                        break;
                    case 's':  /* Specifier '%s' */
                        str = va_arg(args, char *);
                        if (!str)
                            str = "(null)";
                        while (*str)
                            print_char(*str++, &count);
                        break;
                    case '%':   /* Specifier '%' */
                        print_char('%', &count);
                        break;
                    case 'd':  /* Specifier 'd' */
                    case 'i':  /* Specifier 'i' */
                        num = va_arg(args, int);
                        print_number(num, &count);
                        break;
                    case 'b':   /* Binary */
                        print_binary(va_arg(args, unsigned int), &count);
                        break;
                    case 'o':  /* Octal */
                        print_octal(va_arg(args, unsigned int), &count);
                        break;
                    case 'u':  /* Unsigned int */
                        print_unsigned(va_arg(args, unsigned int), &count);
                        break;
                    case 'x':  /* Hexadecimal lowercase */
                        print_hex(va_arg(args, unsigned int), &count);
                        break;
                    case 'X':  /* Hexadecimal UPPERCASE */
                        print_upper_hex(va_arg(args, unsigned int), &count);
                        break;
                    default:
                        print_char('%', &count);
                        print_char(*format, &count);
                        break;
                }
            }
        }
        else if (*format == '%' && *(format + 1) == '\0')
        {
            /* Lone '%' at the end */
            return (-1);
        }
        else
        {
            print_char(*format, &count);
        }

        format++;
    }

    va_end(args);
    flush_buffer();  /* Flush remaining characters in the buffer */
    return (count);
}