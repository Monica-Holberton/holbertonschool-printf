#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf2(const char *format, ...);
int _printf(const char *format, ...);

void print_char(char c, int *count); /* Prints a character to stdout and updates count */
void print_number(int n, int *count); /* Prints an integer (handles negatives) and updates count */

#endif /* MAIN_H */