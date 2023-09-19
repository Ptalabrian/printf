#include "main.h"

/**
* print_char - prints a character
* @arg: argument to be printed
* Return: a character
*/

int print_char(va_list arg)
{
	char c = va_arg(arg, int);

	write(1, &c, 1);
}

/**
* print_string - prints a string
* @arg: argument to be printed
* Return: a string
*/

int print_string(va_list arg)
{
	char *str = va_arg(arg, char *);
	int l = 0;

	while (str[l] != '\0')
		l++;

	write(1, str, l);
}

/**
* print_perc - prints a percentage sign
* @arg: argument to be printed
* Return: a percent sign
*/

int print_perc(va_list arg)
{
	char perc = '%';

	write(1, &perc, 1);
}
