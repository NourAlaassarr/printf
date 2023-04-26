#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * get_type - function that finds format if avaliable
 * @c: string
 * @ptr: pointer
 * @p: parameter
 * Return: total count of bytes printed
 * */

int (*get_type(char *c))(va_list ptr, params_ *p)
{
	specifier_ spec[] = {
		{"s", print_string},
		{"c", print_characters},
		{"i", int_print},
		{"d", int_print},
		{"%", percent_print},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"S", print_S},
		{"R", print_rotation},
		{"r", print_reverse},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{NULL, NULL}
	};
	int i;
	while (spec[i].speci)
	{
		if (*c == spec[i].speci[0])
		{
			return (spec[i].s);
		}
		i++;
	}
	return (NULL);
}
