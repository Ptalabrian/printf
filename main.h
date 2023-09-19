#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
* struct formatspec - defines the format to be printed
* @specifier: char that represents the format
* @handler: handles on what to be printed
*/

typedef struct formatspec {
	char specifier;
	int (*handler)(va_list arg);
}formatspec_t;

/** Function prototypes required **/
 int _printf(const char *format, ...);

int print_char(va_list arg);
int print_string(va_list arg);
int print_perc(va_list arg);

#endif
