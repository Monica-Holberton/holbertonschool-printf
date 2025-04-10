#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
* _printf - Custom printf that handles %c, %s, %d, %i and %%
* @format: Format string
* Return: Number of characters printed
*/
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
char *str;
char ch;
int num;

if (!format)
return (-1); /* Null check */

va_start(args, format);

while (*format)
{
if (*format == '%' && *(format + 1))
{
format++; /* Move to specifier */
switch (*format)
{
case 'c':
ch = va_arg(args, int);
write(1, &ch, 1);
count++;
break;
case 's':
str = va_arg(args, char *);
if (!str)
str = "(null)";
while (*str)
{
write(1, str++, 1);
count++;
}
break;
case '%':
write(1, "%", 1);
count++;
break;
case 'd':
case 'i':
num = va_arg(args, int);
print_number(num, &count);
break;
default:
write(1, "%", 1);
write(1, format, 1);
count += 2;
break;
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