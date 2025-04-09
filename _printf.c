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
{
return (-1);  /* Null check */
}

va_start(args, format);

while (*format)
{
if (*format == '%' && *(++format))   /* Check for format specifier */
{
if (*format == 'd' || *format == 'i')
{
int n = va_arg(args, int);
print_number(n, &count);  /* Print the number */
}
else if (*format == 's')
{
str = va_arg(args, char *);
while (*str)
{
print_char(*str, &count);  /* Print characters of the string */
str++;
}
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
