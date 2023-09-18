#include "main.h"
/**
* _printf - produces output according to a format.
* @format: the character string
* Return: 0
*/
int _printf(const char *format, ...);
int _printf(const char *format, ...)
{
	int print_c = 0;
	va_list args;
	char *str;
	char c;
	int str_len;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			print_c++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, "%", 1);
				print_c++;
			}
			else if (*format == 'c')
			{
				c = va_arg(args, int);
				write(1, &c, 1);
				print_c++;
			}
			else if (*format == 's')
			{
				str = va_arg(args, char*);
				if (str != NULL)
				{
					str_len = 0;
					while (str[str_len] != '\0')
					{
						str_len++;
					}
					write(1, str, str_len);
					print_c += str_len;
				}
			}
			format++;
		}
	}
	va_end(args);
	return (print_c);
}
