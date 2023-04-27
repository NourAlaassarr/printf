#include "main.h"

/**
 * print_hexanum - Prints a hexadecimal number in lower or upper
 * @types: arguments list
 * @map_to: Array of values to map the number to
 * @buff: printing array
 * @flags: active flags
 * @flag_ch: Calculates active flags
 * @width: width calculated
 * @precision: precision calculated
 * @size: size calculated
 * Return: printed nummbers
 */

int print_hexanum(va_list types, char map_to[],
char buff[], int flags, char flag_ch, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = converting_unsign(num, size);

	if (num == 0)
		buff[j--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buff[j--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & HASHTAG_FLAG && init_num != 0)
	{
		buff[j--] = flag_ch;
		buff[j--] = '0';
	}

	j++;

	return (write_unsigned(0, j, buff, flags, width, precision, size));
}


/**
 * print_unsigned - prints unsigned integers
 * @types: arguments list
 * @buff: printing array
 * @flags: active flags
 * @width: width calculated
 * @precision: precision calculated
 * @size: size calculated
 * Return: printed nummbers
 */

int print_unsigned(va_list types, char buff[],
	int flags, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = converting_unsign(num, size);

	if (num == 0)
		buff[j--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buff[j--] = (num % 10) + '0';
		num /= 10;
	}

	j++;

	return (write_unsigned(0, j, buff, flags, width, precision, size));
}
