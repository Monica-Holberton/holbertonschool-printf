#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/*Function prototypes*/
int _printf2(const char *format, ...);
int _printf(const char *format, ...);

void print_char(char c, int *count); /* Prints a character to stdout and updates count */
void print_number(int n, int *count); /* Prints an integer (handles negatives) and updates count */

void add_to_buffer(char c, int *count);  /*Function prototype for add_to_buffer*/
void flush_buffer();  /*Function prototype for flush_buffer*/

#endif /* MAIN_H */
