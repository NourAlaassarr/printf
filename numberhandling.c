#include "main.h"

/**
 * print_hex - prints lowercase unsigned hex numbers
 * @types: arguments list
 * @buff: printing array
 * @flags: active flags
 * @width: width calculated
 * @precision: precision calculated
 * @size: size calculated
 * Return: printed nummbers
 */

int print_hex(va_list types, char buff[],
	int flags, int width, int precision, int size)
{
	return (print_hexanum(types, "0123456789abcdef", buff,
		flags, 'x', width, precision, size));
}


/**
 * print_HEX - prints uppercase unsigned hex numbers
 * @types: arguments list
 * @buff: printing array
 * @flags: active flags
 * @width: width calculated
 * @precision: precision calculated
 * @size: size calculated
 * Return: printed nummbers
 */

int print_HEX(va_list types, char buff[],
	int flags, int width, int precision, int size)
{
	return (print_hexanum(types, "0123456789ABCDEF", buff,
		flags, 'X', width, precision, size));
}


/**
 * print_binary - prints binary unsigned numbers
 * @types: arguments list
 * @buff: printing array
 * @flags: active flags
 * @width: width calculated
 * @precision: precision calculated
 * @size: size calculated
 * Return: printed nummbers
 */

int print_binary(va_list types, char buff[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, j, sum;
	unsigned int a[32];
	int count;

	UNUSED(buff);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (j = 1; j < 32; j++)
	{
		m /= 2;
		a[j] = (n / m) % 2;
	}
	for (j = 0, sum = 0, count = 0; j < 32; j++)
	{
		sum += a[j];
		if (sum || j == 31)
		{
			char z = '0' + a[j];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}


/**
 * print_octal - prints octal unsigned numbers
 * @types: arguments list
 * @buff: printing array
 * @flags: active flags
 * @width: width calculated
 * @precision: precision calculated
 * @size: size calculated
 * Return: printed nummbers
 */

int print_octal(va_list types, char buff[],
	int flags, int width, int precision, int size)
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
		buff[j--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & HASHTAG_FLAG && init_num != 0)
		buff[j--] = '0';

	j++;

	return (write_unsigned(0, j, buff, flags, width, precision, size));
}


/**
 * int_print - function to print int
 * @types: arguments list
 * @buff: printing array
 * @flags: active flags
 * @width: width calculated
 * @precision: precision calculated
 * @size: size calculated
 * Return: printed nummbers
 */

int int_print(va_list types, char buff[],
	int flags, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = converting_num(n, size);

	if (n == 0)
		buff[j--] = '0';

	buff[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buff[j--] = (num % 10) + '0';
		num /= 10;
	}

	j++;

	return (write_numb(is_negative, j, buff, flags, width, precision, size));
}
