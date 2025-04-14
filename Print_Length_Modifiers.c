#include "main.h"
void print_length(va_list args, char specifier, char *length, int *count)
{
    {
        length++; /* go to check after h*/
        int len = 0;
        int num = args;
        /* check number of digits in number*/
        while(num)
        {
            len++;
            num /= 10;
        }
        if (*length == 'i' || length == 'u' || length == 'd')
        {
                /* if number aready short*/
                if (len <= 5)
                {
                    print_number(args, count);
                }
                else
                {
                    /**/
                    while(args > 99999)
                    {
                        args--;
                    }
                    print_number(args, count);
                }
        }
    }
}
