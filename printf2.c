#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 *_printf - Custom printf for %d and %i
 *@format: Format string
 *Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0, n, div;
char d;
if (!format)
return (-1); /* Null check */
va_start(args, format);
while (*format)
{
if (*format == '%' && *(++format)) /* Check for format specifier */
{
if (*format == 'd' || *format == 'i') /* Handle %d and %i */
{
n = va_arg(args, int);
if (n < 0) /* Handle negative numbers */
{
write(1, "-", 1);
count++;
n = -n;
}
div = 1; /* Find highest place */
while (n / div > 9) /* Check for highest place */
div *= 10;
while (div) /* Print digits */
{
d = '0' + (n / div % 10);
write(1, &d, 1);
count++;
div /= 10;
}
}
else /* Unknown specifier */
{
write(1, "%", 1);
write(1, format, 1);
count += 2;
}
}
else /* Print normal char */
{
write(1, format, 1);
count++;
}
format++;
}
va_end(args);
return (count);
}
