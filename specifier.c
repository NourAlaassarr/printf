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
 */

<<<<<<< HEAD
int(*get_type(char* c))(va_list ptr, params_ *p)
=======
int (*get_type(char *c))(va_list ptr, params_ *p)
>>>>>>> c9244c60d8116b8f016c85de789bd8b3b5e748c7
{
<<<<<<< HEAD
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
{"x", print_hexa},
{"X", print_Upperhexa},
=======
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
>>>>>>> 2663b7e901cf4f756c14f939565adfbc140ba9c4
		{"p", print_address},
		{NULL, NULL}
	};
	int i;
	while (spec[i].speci)
	{
		if (*s == spec[i].speci[0])
		{
			return (spec[i].f);
		}
		i++;
	}
	return (NULL);
}

