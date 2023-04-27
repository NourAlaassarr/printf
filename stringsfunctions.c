#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * print_characters - Prints a char
 * @ptr: pointer
 * @buffer:array to be printed
 * @flag:flag activated
 * @wid: Width
 * @precision: Precision udsed
 * @s: size
 * Return: printed char
 */
int print_characters(va_list ptr, char arr[], int flag, int wid, int precision, int s)
{
        char ch = va_arg(ptr, int);
        return (write_characters(ch, arr, flag, wid, precision, s));
}
/**
 * print_string - Prints a string
 * @ptr: pointer
 * @bufr:array to be printed
 * @flag:flag activated
 * @w: Width
 * @precision: Precision udsed
 * @sz: size
 * Return: printed char
 */
int print_string (va_list ptr, char bfr[],
	int flag, int w, int precision, int sz)
{
	int len = 0, i;
	char *str = va_arg(ptr, char *);

	UNUSED(bfr);
	UNUSED(flag);
	UNUSED(w);
	UNUSED(precision);
	UNUSED(sz);

	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;

	if (w > len)
	{
		if (flag & MINUS_FLAG)
		{
			write(1, &str[0], len);
			for (i = w - len; i > 0; i--)
				write(1, " ", 1);
			return (w);
		}
		else
		{
			for (i = w - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (w);
		}
	}

	return (write(1, str, len));
}

/**
 * percent_print - print string handeled with %
 * @ptr: pointer
 * @p: parameter struct
 *
 * Return: char numbers
 */
int print_percent(va_list ptr, char arr[],
	int flag, int wid, int precision, int s)
{
	UNUSED(ptr);
	UNUSED(arr);
	UNUSED(flag);
	UNUSED(wid);
	UNUSED(precision);
	UNUSED(s);
	return (write(1, "%%", 1));
}
