#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * print_address - print pointer value
 * @ptr: pointer to arg
 * @bfr: array to be printed
 * @flag: activated flag
 * @w: width
 * @pre: Precision 
 * @sz: size
 * Return: chars to be printed
 */

int print_address(va_list ptr, char bfr[],
	int flag, int w, int pre, int sz)
{
	char es = 0, padding = ' ';
	int indentation = BUFF_SIZE - 2, length = 2, p_start = 1; 
	unsigned long address;
	char map_to[] = "0123456789abcdef";
	void *pointeradrs = va_arg(ptr, void *);

	UNUSED(w);
	UNUSED(sz);

	if (pointeradrs == NULL)
		return (write(1, "(nil)", 5));

	bfr[BUFF_SIZE - 1] = '\0';
	UNUSED(pre);

	address = (unsigned long)pointeradrs;

	while (address > 0)
	{
		bfr[indentation--] = map_to[address % 16];
		address /= 16;
		length++;
	}

	if ((flag & ZERO_FLAG) && !(flag & MINUS_FLAG))
		padding = '0';
	if (flag & PLUS_FLAG)
		es = '+', length++;
	else if (flag & SPACE_FLAG)
		es = ' ', length++;

	indentation++;

	return (pointer_writing(bfr, indentation, length,
		w, flag, padding, es, p_start));
}
/**
 * non_print - Print ascii code
 * @ptr: pointer to arg
 * @bfr: array to be printed
 * @flag: activated flag
 * @w: width
 * @pre: Precision
 * @sz: size
 * Return: chars to be printed
 */
int non_print(va_list ptr, char bfr[],
	int flag, int w, int pre, int sz)
{
	int i = 0, biteoffset = 0;
	char *stringg = va_arg(ptr, char *);

	UNUSED(flag);
	UNUSED(w);
	UNUSED(pre);
	UNUSED(sz);

	if (stringg == NULL)
		return (write(1, "(null)", 6));

	while (stringg[i] != '\0')
	{
		if (checkifprintable(stringg[i]))
			bfr[i + biteoffset] = stringg[i];
		else
			biteoffset += hexa_appened(stringg[i], bfr, i + biteoffset);

		i++;
	}

	bfr[i + biteoffset] = '\0';

	return (write(1, bfr, i + biteoffset));
}

/**
 * print_reverse - Print reversed 
 * @ptr: pointer to arg
 * @bfr: array to be printed
 * @flag: activated flag
 * @w: width
 * @pre: Precision
 * @sz: size
 * Return: chars to be printed
 */
int print_reverse(va_list ptr, char bfr[],
	int flag, int w, int pre, int sz)
{
	char *stringg;
	int i, count = 0;

	UNUSED(bfr);
	UNUSED(flag);
	UNUSED(w);
	UNUSED(sz);

	stringg = va_arg(ptr, char *);

	if (stringg == NULL)
	{
		UNUSED(pre);

		stringg = ")Null(";
	}
	for (i = 0; stringg[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char tmp = stringg[i];

		write(1, &tmp, 1);
		count++;
	}
	return (count);
}
/**
 * print_rotation - Print reversed
 * @ptr: pointer to arg
 * @bfr: array to be printed
 * @flag: activated flag
 * @w: width
 * @pre: Precision
 * @sz: size
 * Return: chars to be printed
 */
int print_rotation(va_list ptr, char bfr[],
	int flag, int w, int pre, int sz)
{
	char ch;
	char *stringg;
	unsigned int i, j;
	int sum = 0;
	char rotation[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";


	stringg = va_arg(ptr, char *);
	UNUSED(bfr);
	UNUSED(flag);
	UNUSED(w);
	UNUSED(pre);
	UNUSED(sz);

	if (stringg == NULL)
		stringg = "(AHYY)";
	for (i = 0; stringg[i]; i++)
	{
		for (j = 0; input[j]; j++)
		{
			if (input[j] == stringg[i])
			{
				ch = rotation[j];
				write(1, &ch, 1);
				sum++;
				break;
			}
		}
		if (!input[j])
		{
			ch = stringg[i];
			write(1, &ch, 1);
			sum++;
		}
	}
	return (sum);
}
