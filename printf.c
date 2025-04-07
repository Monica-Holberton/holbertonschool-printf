#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
*_printf - Custom printf that handles %c, %s and %%
*@format: Format string
*Return: Number of characters printed
*/
int _printf(const char *format, ...)
{
int count = 0, i;
char *str;
va_list args;

if (!format) /* return error if format is NULL */
return (-1);

va_start(args, format);
while (*format) /* loop each character in format string */
{
if (*format == '%')
{
format++;
if (!*format)
return (-1); /* error if '%' is last char */
if (*format == 'c') /* character case */
{
char c = va_arg(args, int);
write(1, &c, 1), count++;
}
else if (*format == 's') /* string case */
{
str = va_arg(args, char *);
for (i = 0; str[i]; i++, count++) /* loop string */
write(1, &str[i], 1);
}
else if (*format == '%') /* percentage case */
write(1, "%", 1), count++;
else /* unknown specifier */
write(1, "%", 1), write(1, format, 1), count += 2;
}
else
write(1, format, 1),
count++;
format++;
}
va_end(args);
return (count); /* return total characters printed */
}
