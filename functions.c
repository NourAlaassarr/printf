#include "main.h"

/**
 * converting - function to convert integers to strings
 * @number: number entered
 * @base: base of number
 * @flags: flags entered
 * @p: parameter struct
 * Return: string
 */

char *converting(long int number, int base, int flags, params_ *p)
{
	static char *arr;
	static char buff[50];
	char sign = 0;
	char *ptr;
	unsigned long n = number;
	(void)p;

	if (!(flags & CONVERT_UNSIGNED) && number < 0)
	{
		n = -number;
		sign = '-';
	}
	arr = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buff[49];
	*ptr = '\0';

	do  {
		*--ptr = arr[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}


/**
 * print_unsigned - prints unsigned integers
 * @ap: pointer to argument
 * @p: parameters structure
 * Return: printed integers
 */

int print_unsigned(va_list ap, params_ *p)
{
	unsigned long lo;

	if (p->lmodifier)
		lo = (unsigned long)va_arg(ap, unsigned long);
	else if (p->hmodifier)
		lo = (unsigned short int)va_arg(ap, unsigned int);
	else
		lo = (unsigned int)va_arg(ap, unsigned int);
	p->unsign = 1;
	return (printnumbers(converting(lo, 10, CONVERT_UNSIGNED, p), p));
}


/**
 * print_address - prints an address
 * @ap: pointer to argument
 * @p: parameters structure
 * Return: printed address
 */

int print_address(va_list ap, params_ *p)
{
	unsigned long int m = va_arg(ap, unsigned long int);
	char *s;

	if (!m)
		return (_puts("(nil)"));

	s = converting(m, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, p);
	*--s = 'x';
	*--s = '0';
	return (printnumbers(s, p));
}
