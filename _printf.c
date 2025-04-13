#include "main.h"
#include <stdarg.h>
#include <unistd.h>

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

            /* Check for precision */
            if (*format == '.')
            {
                format++;
                format += get_precision(format, &precision);

                if (*format == 'd' || *format == 'i')
                {
                    num = va_arg(args, int);
                    print_number_precision(num, precision, &count);
                }
                /* Add precision for %s if needed later */
            }
            else
            {
                switch (*format)
                {
                    case 'c': /*Specifier '%c'*/
                        ch = va_arg(args, int);
                        write(1, &ch, 1);
                        count++;
                        break;
                    case 's': /*Specifier '%s'*/
                        str = va_arg(args, char *);
                        if (!str)
                            str = "(null)";
                        while (*str)
                        {
                            write(1, str++, 1);
                            count++;
                        }
                        break;
                    case '%': /*Specifier '%'*/
                        write(1, "%", 1);
                        count++;
                        break;
                    case 'd': /*Specifier 'd'*/
                    case 'i': /*Specifier 'i'*/
                        num = va_arg(args, int);
                        print_number(num, &count);
                        break;
                    case 'b':  /*Binary*/
                        print_binary(va_arg(args, unsigned int), &count);
                        break;
                    case 'o':  /*Octal*/
                        print_octal(va_arg(args, unsigned int), &count);
                        break;
                    case 'u':  /*Unsigned int*/
                        print_unsigned(va_arg(args, unsigned int), &count);
                        break;
                    //case 'x':
                        //print_hex(va_arg(args, unsigned int), &count);
                        //break;
                   // case 'X':
                        //print_upper_hex(va_arg(args, unsigned int), &count);
                        //break;
                    default:
                        write(1, "%", 1);
                        write(1, format, 1);
                        count += 2;
                        break;
                }
            }
        }
        else if (*format == '%' && *(format + 1) == '\0')
        {
            /* Lone '%' at end of string */
            return (-1);
        }
        else
        {
            write(1, format, 1);
            count++;
        }

        format++;
    }

    va_end(args);
    return (count);
}