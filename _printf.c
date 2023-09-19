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
	{'c', print_char},
	{'s', print_string},
	{'%', print_perc}
};
	int size = sizeof(formtspec) / sizeof(formtspec[0]);

	va_start(arg, format);

	if (format == NULL)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;

			for (i = 0; i < size; i++)
			{
				if (*format == formtspec[i].specifier)
				{
					count += formtspec[i].handler(arg);
					break;
				}
			}
		}
		else
		{
			write(1, format, 1);
			count++;
		}

		if (*format == '\0')
			break;
		format++;
	}
	va_end(arg);
	return (count);
}
