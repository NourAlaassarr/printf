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
char buff[], int flags, char flag_ch, int width, int precision, int size);
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

	if (flags & F_HASH && init_num != 0)
	{
		buff[j--] = flag_ch;
		buff[j--] = '0';
	}

	j++;

	return (write_unisgned(0, j, buff, flags, width, precision, size));
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
	int flags, int width, int precision, int size);
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


/**
 * print_address - prints an address
 * @types: arguments list
 * @buff: printing array
 * @flags: active flags
 * @width: width calculated
 * @precision: precision calculated
 * @size: size calculated
 * Return: printed nummbers
 */

int print_address(va_list types, char buff[],
	int flags, int width, int precision, int size);
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, len = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buff[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buff[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', len++;
	else if (flags & F_SPACE)
		extra_c = ' ', len++;

	ind++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (pointer_writing(buff, ind, len,
		width, flags, padd, extra_c, padd_start));
}
