#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
/**
 * getflag - check for flags
 * @format: string to be printed
 * @f: parameter int
 * Return: flag
 */
int getflag(const char *format, int *f)
{
	int i, current;
	int flag = 0;
	const char flag_ch[] = {'-', '+', '0', '#', ' ', '\0'};
	const int arr_of_flags[] = {MINUS_FLAG, PLUS_FLAG,
		ZERO_FLAG, HASHTAG_FLAG, SPACE_FLAG, 0};

	for (current = *f + 1; format[current] != '\0'; current++)
	{
		for (i = 0; flag_ch[i] != '\0'; i++)
			if (format[current] == flag_ch[i])
			{
				flag |= arr_of_flags[i];
				break;
			}
		if (flag_ch[i] == 0)
			break;
	}
	*f = current - 1;
	return (flag);
}
/**
 * getwidth -  width to be printed
 * @format: string to be printed
 * @w: num of arguments
 * @ptr: argument list
 * Return: width as int
 */
int getwidth(const char *format, int *w, va_list ptr)
{
	int current, widthn = 0;

	for (current = *w + 1; format[current] != '\0'; current++)
	{
		if (isdigit_(format[current]))
		{
			widthn *= 10;
			widthn += format[current] - '0';
		}
		else if (format[current] == '*')
		{
			current++;
			widthn = va_arg(ptr, int);
			break;
		}
		else
			break;
	}
	*w = current - 1;
	return (widthn);
}

/**
 * getprecision - precision to be printed
 * @format:string
 * @p:arguments number
 * @ptr: pointer to struct
 * Return: Precision
 */

int getprecision(const char *format, int *p, va_list ptr)
{
	int current = *p + 1;
	int precisionn = -1;

	if (format[current] != '.')
		return (precisionn);
	precisionn = 0;
	for (current += 1; format[current] != '\0'; current++)
	{
		if (isdigit_(format[current]))
		{
			precisionn *= 10;
			precisionn += format[current] - '0';
		}
		else if (format[current] == '*')
		{
			current++;
			precisionn = va_arg(ptr, int);
			break;
		}
		else
			break;
	}
	*p = current - 1;
	return (precisionn);
}

/**
 * getsize - get size of converting arg
 * @format: string to be printed
 * @s: number of arguments
 * Return: size
 */
int getsize(const char *format, int *s)
{
	int count = 0;
	int current = *s + 1;

	if (format[current] == 'l')
		count = LONG_N;
	else if (format[current] == 'h')
		count = SHORT_N;
	if (count == 0)
		*s = current - 1;
	else
		*s = current;
	return (count);
}
