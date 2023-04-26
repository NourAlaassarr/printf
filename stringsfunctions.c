#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
/**
 * print_characters - function used to print number of char
 * @ptr: pointer
 * @p: parameter to struct
 *
 * Return: integer number of char
 */

int print_characters(va_list ptr, params_ *p)
{
	int count = 0;
	char charr = ' ';
	unsigned int padding = 1, ch;

	ch = va_arg(ptr, int);
	if (p->minus_flag)
		count += _putchar(ch);
	while (padding++ < p->width)
		count += _putchar(charr);
	if (!p->minus_flag)
		count += _putchar(ch);
	return (count);
}

/**
 * int_string - function to print string num
 * @ptr: pointer
 * @p: parameter to struct
 *
 * Return: integer
 */
int int_string(va_list ptr, params_ *p)
{
	char *s = va_arg(ptr, char *), charr = ' ';
	unsigned int padding = 0, count = 0, i = 0, j;

	(void)p;
	switch ((int)(!s))
	case 1:
		s = NULL_STRING;
	j = padding = strlength(s);
	if (p->precision < padding)
		j = padding = p->precision;
	if (p->minus_flag)
	{
		if (p->precision != UINT_MAX)
			for (i = 0; i < padding; i++)
				count += _putchar(*s++);
		else
			count += _puts(s);
	}
	while (j++ < p->width)
		count += _putchar(charr);
	if (!p->minus_flag)
	{
		if (p->precision != UINT_MAX)
			for (i = 0; i < padding; i++)
				count += _putchar(*s++);
		else
			count += _puts(s);
	}
	return (count);
}

/**
 * percent_print - print string handeled with %
 * @ptr: pointer
 * @p: parameter struct
 *
 * Return: char numbers
 */

int percent_print(va_list ptr, params_ *p)
{
	(void)ptr;
	(void)p;
	return (_putchar('%'));
}
/**
 * print_S - specifier to handel
 * @ptr: pointer
 * @p: parameter struct
 *
 * Return: char number
 */
int print_S(va_list ptr, params_ *p)
{
	char *hexa;
	int count = 0;
	char *s = va_arg(ptr, char *);

	if ((int)(!s))
		return (_puts(NULL_STRING));
	for (; *s; s++)
	{
		if ((*s > 0 && *s < 32) || *s >= 127)
		{
			count += _putchar('\\');
			count += _putchar('x');
			hexa = converting(*s, 16, 0, p);
			if (!hexa[1])
				count += _putchar('0');
			count += _puts(hexa);
		}
		else
			count += _putchar(*s);
	}
	return (count);
}
