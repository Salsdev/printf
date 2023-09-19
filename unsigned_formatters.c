#include "main.h"

/**
 * print_unsigned - Outputs an unsigned integer.
 * @types: Argument list containing the unsigned number to be printed.
 * @buffer: Array buffer to manage output.
 * @flags: Determines which flags are active.
 * @width: Specifies the width for formatting.
 * @precision: Specifies the precision for formatting.
 * @size: Specifies the size for the argument.
 * Return: The count of characters outputted.
 */
int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_octal - Outputs an unsigned integer in octal format.
 * @types: List of arguments containing the number to be printed.
 * @buffer: Array buffer for managing output.
 * @flags: Identifies active formatting flags.
 * @width: Specifies the width for formatting.
 * @precision: Sets the precision level for formatting.
 * @size: Dictates the size of the argument.
 * Return: Count of characters produced.
 */
int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}
	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - Outputs an unsigned integer in hexadecimal format.
 * @types: List of arguments containing the number to be printed.
 * @buffer: Array buffer for collecting output.
 * @flags: Identifies active formatting flags.
 * @width: Specifies the minimum width for formatting.
 * @precision: Indicates the precision level for formatting.
 * @size: Designates the size of the argument.
 * Return: Count of characters produced.
 */
int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
				flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - Outputs an unsigned integer in uppercase hexadecimal.
 * @types: List of arguments containing the number to be printed.
 * @buffer: Array buffer for collecting output.
 * @flags: Identifies active formatting flags.
 * @width: Specifies the minimum width for formatting.
 * @precision: Indicates the precision level for formatting.
 * @size: Designates the size of the argument.
 * Return: Count of characters produced.
 */
int print_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{'
	return (print_hexa(types, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}

/**
*print_hexa - Outputs a number in hexadecimal format
* @types: List of arguments containing the number to be printed.
* @map_to: Mapping array to determine hexadecimal representation
* @buffer: Array buffer for assembling output.
* @flags: Identifies active formatting flags.
* @flag_ch: Character indicating the case for formatting.
* @width: Specifies the minimum width for formatting.
* @precision: Indicates the precision level for formatting.
* @size: Designates the size of the argument.
* Return: Count of characters produced.
*/
int print_hexa(va_list types, char map_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}
	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
