#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
* _printf - Custom printf that handles %c, %s, %d, %i, and %%
* @format: Format string
* Return: Number of characters printed
*/

int _printf(const char *format, ...)
{
va_list args;
int count = 0;
char *str;

if (!format)
return (-1);  /* Null check */

va_start(args, format);

while (*format)
{
if (*format == '%' && *(format + 1)) /* Check for format specifier */
{
format++;
if (*format == 'd' || *format == 'i')  /* Integer */
{
int n = va_arg(args, int);
print_number(n, &count);
}
else if (*format == 's')  /* String */
{
str = va_arg(args, char *);
if (!str)
str = "(null)";
while (*str)
{
print_char(*str, &count);
str++;
}
}
else if (*format == 'c')  /* Character */
{
char c = va_arg(args, int);
print_char(c, &count);
}
else if (*format == '%')  /* Percent sign */
{
print_char('%', &count);
}
else  /* Unknown specifier */
{
print_char('%', &count);
print_char(*format, &count);
}
}
else
{
print_char(*format, &count);
}
format++;
}

va_end(args);
return (count);
}
