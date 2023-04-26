#include "main.h"

/**
 * print_rotation - prints in rotation
 * @ap: pointer to argument
 * @p: parameter structure
 * Return: printed bytes
 */

int print_rotation(va_list ap, params_ *p)
{
	int i, ind;
	int c = 0;
	char arr[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char*);
	(void)p;

	i = 0;
	ind = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
				|| (a[i] >= 'a' && a[i] <= 'z'))
		{
			ind = a[i] - 65;
			c += _putchar(arr[ind]);
		}
		else
			c += _putchar(a[i]);
		i++;
	}
	return (c);
}


/**
 * print_all - prints a range of char addresses
 * @beg: starting address
 * @last: stopping address
 * @not: except address
 * Return: no. of bytes printed
 */

int print_all(char *beg, char *last, char *not)
{
	int sum = 0;

	while (beg <= last)
	{
		if (beg != not)
			sum += _putchar(*beg);
		beg++;
	}
	return (sum);
}


/**
 * print_reverse - prints in reverse
 * @ap: pointer to argument
 * @p: parameter structure
 * Return: bytes in reverse
 */

int print_reverse(va_list ap, params_ *p)
{
	int len, sum = 0;
	char *s = va_arg(ap, char *);
	(void)p;

	if (s)
	{
		for (len = 0; *s; s++)
			len++;
		s--;
		for (; len > 0; len--, s--)
			sum += _putchar(*s);
	}
	return (sum);
}


/**
 * print_function - looks for specifier
 * @c: string
 * @p: pointer to argument
 * @parameters: parameters structure
 * Return: printed bytes
 */

int print_function(char *c, va_list p, params_ *parameters)
{
	int (*s)(va_list, params_ *) = get_type(c);

	if (s)
		return (s(p, parameters));
	return (0);
}

