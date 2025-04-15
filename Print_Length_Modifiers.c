#include "main.h"
#include <stdarg>
void print_length(va_list args, char specifier, char *length, int *count)
{
    {
        if (specifier == 'h')
        {
            length++; /* go to check after h*/
            int num =  va_arg(args, int); 
            /* check number of digits in number*/

            if (*length == 'i' || *length == 'u' || *length == 'd')
            {                        
                short sn = (short) num;
                print_short(num, count);
            }
        }
        else  /* if format is l */
        {
            length++ /* check after l*/
            if (*length == 'l')
            {
                if   
            }
        }
    }
}
