#include "main.h"
#include <stdlib.h>
int print_short(short n, int *count)
{
    char *short_number = (char *) malloc(6 * sizeof(char)); /*5 digits*/
    int i = 0;
    if (n == 0)
    {
        print_char('0', count);
    }
    else
    {
        if (n < 0)
        {
            print_char('-', count);
            n = -n;
        }
        while (n) /* n > 0 */
        {
            short_number[i] = n % 10 + '0';
            n /= 10;
            i++;
        }
        while(i--) /* decrese i untill i = 0*/
        {
            print_char(short_number[i],count);
        }
    }
    return (0);
}