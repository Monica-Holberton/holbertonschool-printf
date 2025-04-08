#include "main.h"
#include <stdarg.h>
#include <unistd.h>

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
if (*format == '%' && *(++format))  /* Check for format specifier */
{
if (*format == 'd' || *format == 'i')  /* Handle %d and %i */
{
int n = va_arg(args, int);
print_number(n, &count);  /* Use helper function for printing numbers */
}
else if (*format == 's')  /* Handle %s */
{
str = va_arg(args, char *);
if (!str)
str = "(null)";
while (*str)
{
print_char(*str, &count);  /* Use helper function for printing chars */
str++;
}
}
else  /* Unknown specifier */
{
print_char('%', &count);
print_char(*format, &count);
}
}
else  /* Print normal char */
{
print_char(*format, &count);
}
format++;
}
va_end(args);
return (count);
}
