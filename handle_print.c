#include "main.h"

/**
 * handle_print - Prints arguments based on their type
 * @fmt: Formatted string to print the arguments.
 * @list: List of arguments printed.
 * @ind: ind.
 * @buff: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: getwidth.
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: 1 or 2;
 */

int handle_print(const char *fmt, int *ind, va_list list, char buff[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_characters}, {'s', print_string}, {'%', percent_print},
		{'i', int_print}, {'d', int_print}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hex},
		{'X', print_HEX}, {'p', print_address}, {'S', non_print},
		{'r', print_reverse}, {'R', print_rotation}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buff, flags, width, precision, size));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
