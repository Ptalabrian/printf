#include "main.h"

/**
* _printf - function that produces output according to a format
* @format: what to be printed
*
* Return: no. of characters printed
*/

int _printf(const char *format, ...)
{
	va_list arg;
	int count = 0, i;
	formatspec_t formtspec[] = {
	{'c', print_char}, {'s', print_string},
	{'%', print_perc} };
	int size = sizeof(formtspec) / sizeof(formtspec[0]);
	const char *p = format;

	va_start(arg, format);
	if (p == NULL)
		return (-1);
	while (*p)
	{
		if (*p == '%')
		{
			p++;
			if (*p)
			{
				for (i = 0; i < size; i++)
				{
					if (*p == formtspec[i].specifier)
					{
						count += formtspec[i].handler(arg);
						break;
					}
				}
			}
			if (*p == '\0')
				break;
		}
		else
		{
			write(1, p, 1);
			count++;
		}
		p++;
	}
	va_end(arg);
	return (count);
}
