#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
/**
 * isdigit_ - checks for digits
 * @numb: char to check
 * Return: 1 if yes, 0 if not
 */

int isdigit_(char numb)
{
	if (numb >= '0' && numb <= '9')
		return (1);
	return (0);
}

/**
 * hexa_appened - Append  hexadecimal to array
 * @arr: Array of characters
 * @j: start appending
 * @asci: ASSCI code num
 * Return: int num 3
 */

int hexa_appened(char asci, char arr[], int j)
{
	char map_to[] = "0123456789ABCDEF";

	if (asci < 0)
		asci *= -1;

	arr[j++] = '\\';
	arr[j++] = 'x';

	arr[j++] = map_to[asci / 16];
	arr[j] = map_to[asci % 16];

	return (3);
}

/**
 * checkifprintable - function to check if char is printable
 * @p: character to check
 *
 * Return: 1 if c is printable, 0 otherwise
 */

int checkifprintable(char p)
{
	if (p >= 32 && p < 127)
		return (1);

	return (0);
}

/**
 * converting_num - convert data type
 * @n: Num to convert
 * @s: data type to be converted to
 *
 * Return: value of converting
 */

long int converting_num(long int n, int s)
{
	if (s == LONG_N)
		return (n);
	else if (s == SHORT_N)
		return ((short)n);

	return ((int)n);
}

/**
 * converting_unsign - convert to another size
 * @n: Num to convert
 * @s: data type to be converted to
 *
 * Return: value of converting
 */

long int converting_unsign(unsigned long int n, int s)
{
	if (s == LONG_N)
		return (n);
	else if (s == SHORT_N)
		return ((unsigned short)n);

	return ((unsigned int)n);
}
