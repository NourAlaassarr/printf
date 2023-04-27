#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"

/**
 * write_characters - Prints a string
 * @ch: char types.
 * @bfr: Buffer array to handle print
 * @flag:  Calculates active flags.
 * @w: get width.
 * @pre: precision specifier
 * @sz: Size specifier
 *
 * Return: Number of chars printed
 */

int write_characters(char ch, char bfr[],
	int flag, int w, int pre, int sz)
{
	int i = 0;
	char padding = ' ';

	UNUSED(pre);
	UNUSED(sz);

	if (flag & ZERO_FLAG)
		padding = '0';

	bfr[i++] = ch;
	bfr[i] = '\0';

	if (w > 1)
	{
		bfr[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < w - 1; i++)
			bfr[BUFF_SIZE - i - 2] = padding;

		if (flag & MINUS_FLAG)
			return (write(1, &bfr[0], 1) +
					write(1, &bfr[BUFF_SIZE - i - 1], w - 1));
		else
			return (write(1, &bfr[BUFF_SIZE - i - 1], w - 1) +
					write(1, &bfr[0], 1));
	}

	return (write(1, &bfr[0], 1));
}

/**
 * number_writing - print number in buffer
 * @ind: Index of start
 * @bfr: Buffer
 * @flag: Flags
 * @w: width
 * @prec: Precision
 * @l: length
 * @padd: Padding character
 * @extra: Extra char
 *
 * Return: Number of printed chars.
 */

int number_writing(int ind, char bfr[], int flag, int w, int prec,
	int l, char padd, char extra)
{
	int i, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && bfr[ind] == '0' && w == 0)
		return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && bfr[ind] == '0')
		bfr[ind] = padd = ' ';
	if (prec > 0 && prec < l)
		padd = ' ';
	while (prec > l)
		bfr[--ind] = '0', l++;
	if (extra != 0)
		l++;
	if (w > l)
	{
		for (i = 1; i < w - l + 1; i++)
			bfr[i] = padd;
		bfr[i] = '\0';
		if (flag & MINUS_FLAG && padd == ' ')
		{
			if (extra)
				bfr[--ind] = extra;
			return (write(1, &bfr[ind], l) + write(1, &bfr[1], i - 1));
		}
		else if (!(flag & MINUS_FLAG) && padd == ' ')
		{
			if (extra)
				bfr[--ind] = extra;
			return (write(1, &bfr[1], i - 1) + write(1, &bfr[ind], l));
		}
		else if (!(flag & MINUS_FLAG) && padd == '0')
		{
			if (extra)
				bfr[--padd_start] = extra;
			return (write(1, &bfr[padd_start], i - padd_start) +
				write(1, &bfr[ind], l - (1 - padd_start)));
		}
	}
	if (extra)
		bfr[--ind] = extra;
	return (write(1, &bfr[ind], l));
}

/**
 * write_numb - function to Print a string
 * @ispos: arguments
 * @ind: char
 * @bfr: array to be printed
 * @flag: activated flag
 * @w: width
 * @pre: precision
 * @sz: size
 *
 * Return: chars to print
 */

int write_numb(int ispos, int ind, char bfr[],
	int flag, int w, int pre, int sz)
{
	int len = BUFF_SIZE - ind - 1;
	char padding = ' ', extra = 0;

	UNUSED(sz);

	if ((flag & ZERO_FLAG) && !(flag & MINUS_FLAG))
		padding = '0';
	if (ispos)
		extra = '-';
	else if (flag & PLUS_FLAG)
		extra = '+';
	else if (flag & SPACE_FLAG)
		extra = ' ';

	return (number_writing(ind, bfr, flag, w, pre,
		len, padding, extra));
}

/**
 * pointer_writing - print address
 * @bfr: array of char
 * @ind: start index
 * @len: length
 * @w: width
 * @flag: Flag activated
 * @padding: char for padding
 * @extra: extra char for padding
 * @p_start: start index
 *
 * Return: print number of chars
 */

int pointer_writing(char bfr[], int ind, int len,
	int w, int flag, char padding, char extra, int p_start)
{
	int i;

	if (w > len)
	{
		for (i = 3; i < w - len + 3; i++)
			bfr[i] = padding;
		bfr[i] = '\0';
		if (flag & MINUS_FLAG && padding == ' ')
		{
			bfr[--ind] = 'x';
			bfr[--ind] = '0';
			if (extra)
				bfr[--ind] = extra;
			return (write(1, &bfr[ind], len) + write(1, &bfr[3], i - 3));
		}
		else if (!(flag & MINUS_FLAG) && padding == ' ')
		{
			bfr[--ind] = 'x';
			bfr[--ind] = '0';
			if (extra)
				bfr[--ind] = extra;
			return (write(1, &bfr[3], i - 3) + write(1, &bfr[ind], len));
		}
		else if (!(flag & MINUS_FLAG) && padding == '0')
		{
			if (extra)
				bfr[--p_start] = extra;
			bfr[1] = '0';
			bfr[2] = 'x';
			return (write(1, &bfr[p_start], i - p_start) +
				write(1, &bfr[ind], len - (1 - p_start) - 2));
		}
	}
	bfr[--ind] = 'x';
	bfr[--ind] = '0';
	if (extra)
		bfr[--ind] = extra;
	return (write(1, &bfr[ind], BUFF_SIZE - ind - 1));
}

/**
 * write_unsigned - writes an unsigned number
 * @negative: check if negative
 * @x: index start num
 * @bfr: char array
 * @flag: Flags activated
 * @w: width
 * @p: Precision
 * @s: size
 *
 * Return: Number of printed characters
 */

int write_unsigned(int negative, int x, char bfr[],
		int flag, int w, int p, int s)
{
	int length = BUFF_SIZE - x - 1, i = 0;
	char padd = ' ';

	UNUSED(negative);
	UNUSED(s);

	if (p == 0 && x == BUFF_SIZE - 2 && bfr[x] == '0')
		return (0);
	if (p > 0 && p < length)
		padd = ' ';
	while (p > length)
	{
		bfr[--x] = '0';
		length++;
	}
	if ((flag & ZERO_FLAG) && !(flag & MINUS_FLAG))
		padd = '0';
	if (w > length)
	{
		for (i = 0; i < w - length; i++)
			bfr[i] = padd;
		bfr[i] = '\0';
		if (flag & MINUS_FLAG)
		{
			return (write(1, &bfr[x], length) + write(1, &bfr[0], i));
		}
		else
		{
			return (write(1, &bfr[0], i) + write(1, &bfr[x], length));
		}
	}
	return (write(1, &bfr[x], length));
}
