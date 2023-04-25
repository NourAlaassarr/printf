#include "main.h"

/**
 * _printf - main printf function
 * @format: any format
 * Return: no. of bytes printed
 */

int _printf(const char *format, ...)
{
	int count = 0;
	va_list ptr;
	char *i, *start;

	params_ pr = ADD_PARAM;

	va_start(ptr, format);

	if (format == NULL || format[0] == '%' && !format[1])
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (i = (char *)format; *i; *i++)
	{
		if (*i != '%')
		{
			count += _putchar(*i);
			continue;
		}
		start = i;
		i++;
		while (getflag(i, &pr))
		{
			i++;
		}
		i = getwidth(i, &pr, ptr);
		i = getprecision(i, &pr, ptr);
		if (getmodifier(i, &pr))
			i++;
		if (!get_type(i))
			count += print_all(start, i, pr.lmodifier || pr.hmodifier ? i - 1 : 0);
		else
			count += print_function(i, ptr, &pr);
	}
	_putchar(BUF_FLUSH);
	va_end(ptr);
	return (count);
}
