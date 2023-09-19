#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
* struct formatspec - struct that defines the format specifications
* @specifier: char that represents format
* @handler: pointer to a func for the format specified
*/

typedef struct formatspec
{
	char specifier;
	int (*handler)(va_list arg);
} formatspec_t;

/* Function prototypes required */
int _printf(const char *format, ...);

int print_char(va_list arg);
int print_string(va_list arg);
int print_perc(va_list arg);

#endif
