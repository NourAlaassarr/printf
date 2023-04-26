#include "main.h"

/**
 * print_hex - prints lowercase unsigned hex numbers
 * @ap: pointer to argument
 * @p: parameters struct
 * Return: printed nummbers
 */

int print_hex(va_list ap, params_ *p)
{
	unsigned long l;
	int ch = 0;
	char *str;

	if (p->lmodifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (p->hmodifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = converting(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, p);
	if (p->hashtag_flag && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	p->unsign = 1;
	return (ch += printnumbers(str, p));
}


/**
 * print_HEX - prints uppercase unsigned hex numbers
 * @ap: pointer to argument
 * @p: parameters struct
 * Return: printed nummbers
 */

int print_HEX(va_list ap, params_ *p)
{
	unsigned long l;
	int ch = 0;
	char *str;

	if (p->lmodifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (p->hmodifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = converting(l, 16, CONVERT_UNSIGNED, p);
	if (p->hashtag_flag && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	p->unsign = 1;
	return (ch += printnumbers(str, p));
}


/**
 * print_binary - prints binary unsigned numbers
 * @ap: pointer to argument
 * @p: parameter structure
 * Return: printed binary numbers
 */

int print_binary(va_list ap, params_ *p)
{
	unsigned int m = va_arg(ap, unsigned int);
	char *str = converting(m, 2, CONVERT_UNSIGNED, p);
	int c = 0;

	if (p->hashtag_flag && m)
		*--str = '0';
	p->unsign = 1;
	return (c += printnumbers(str, p));
}


/**
 * print_octal - prints octal unsigned numbers
 * @ap: pointer to argument
 * @p: parameter structure
 * Return: printed octal numbers
 */

int print_octal(va_list ap, params_ *p)
{
	unsigned long ln;
	char *str;
	int v;

	if (p->lmodifier)
		ln = (unsigned long)va_arg(ap, unsigned long);
	else if (p->hmodifier)
		ln = (unsigned short int)va_arg(unsigned int);
	else
		ln = (unsigned int)va_arg(unsigned int);
	str = converting(l, 8 CONVERT_UNSIGNED, p);

	if (p->hashtag && l)
		*--str = '0';
	p->unsign = 1;
	return (v += printnumbers(str, p));
}


/**
 * int_print - function to print int
 * @ap: pointer
 * @p: parameter structure
 * Return: int
 */

int int_print(va_list ap, params_ *p)
{
	long longg;

	if (p->lmodifier)
		longg = va_arg(ap, long);
	else if (p->hmodifier)
		longg = (short int)va_arg(ap, int);
	else
		longg = (int)va_arg(ap, int);
	return (printnumbers(converting(longg, 10, 0, p), p));
}
