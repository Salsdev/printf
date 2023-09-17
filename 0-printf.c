#include "main.h"
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
/**
* _printf - produces output according to a format.
* @format: the character string
* Return: 0
*/
int _printf(const char *format, ...)
{
	int print_c = 0;
	va_list list_of_args;
	char *str;
	char c;

	if (format == NULL)
		return (-1);
	va_start(list_of_args, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			print_c++;
		}
		else if (*(++format) == '\0')
			break;
		if (*format == 'c')
		{
			c = va_arg(list_of_args, int);
			write(1, &c, 1);
			print_c++;
		}
		else if (*format == 's')
		{
			str = va_arg(list_of_args, char*);
			if (str != NULL)
			{
				while (*str)
				{
					write(1, str, 1);
					str++;
					print_c++;
				}
			}
		}
		else if (*format == '%')
		{
			write(1, "%", 1);
			print_c++;
		}
		format++;
	}
	va_end(list_of_args);
	return (print_c);
}
