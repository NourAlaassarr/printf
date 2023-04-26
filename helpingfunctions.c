#include "main.h"

/**
 * isdigit_ - checks for digits
 * @numb: char to check
 * Return: 1 if yes, 0 if not
 */

int isdigit_(int numb)
{
	return (numb >= '0' && numb <= '9');
}


/**
 * _strlength - calculates length of a string
 * @str: string to check
 * Return: length of string
 */

int strlength(char *str)
{
	int j;

	j = 0;
	while (*str++)
		j++;
	return (j);
}


/**
 * printnumber - prints a number
 * @s: string base of the number
 * @p: parameter structure
 * Return: printed chars
 */

int printnumbers(char *s, params_ *p)
{
	unsigned int j = strlength(s);
	int ne = (!p->unsign && *s == '-');

	if (!p->precision && *s == '0' && !s[1])
		s = "";
	if (ne)
	{
		s++;
		j--;
	}
	if (p->precision != UINT_MAX)
		while (j++ < p->precision)
			*--s = '0';
	if (ne)
		*--s = '-';

	if (!p->minus_flag)
		return (print_right_shift(s, p));
	else
		return (print_left_shift(s, p));
}


/**
 * print_right_shift - prints number right justified
 * @s: string base of number
 * @p: parameter structure
 * Return: printed chars
 */

int print_right_shift(char *s, params_ *p)
{
	unsigned int m = 0, ne, ne2, j = strlength(s);
	char pa_ch = ' ';

	if (p->zero_flag && !p->minus_flag)
		pa_ch = '0';
	ne = ne2 = (!p->unsign && *s == '-');
	if (ne && j < p->width && pa_ch == '0' && !p->minus_flag)
		s++;
	else
		ne = 0;
	if ((p->plus_flag && !ne2) ||
		(!p->plus_flag && p->space_flag && !ne2))
		j++;
	if (ne && pa_ch == '0')
		m += _putchar('-');
	if (p->plus_flag && !ne2 && pa_ch == '0' && !p->unsign)
		m += _putchar('+');
	else if (!p->plus_flag && p->space_flag &&
			!ne2 && !p->unsign && p->zero_flag)
		m += _putchar(' ');
	while (j++ < p->width)
		m += _putchar(pa_ch);
	if (ne && pa_ch == ' ')
		m += _putchar('-');
	if (p->plus_flag && !ne2 && pa_ch == ' ' && !p->unsign)
		m += _putchar('+');
	else if (!p->plus_flag && p->space_flag &&
			!ne2 && !p->unsign && !p->zero_flag)
		m += _putchar(' ');
	m += _puts(s);
	return (m);

}


/**
 * print_left_shift - prints number left jutified
 * @s: string base of number
 * @p: parameter structure
 * Return: printed chars
 */

int print_left_shift(char *s, params_ *p)
{
	unsigned int m = 0, ne, ne2, j = strlength(s);
	char pa_ch = ' ';

	if (p->zero_flag && !p->minus_flag)
		pa_ch = '0';
	ne = ne2 = (!p->unsign && *s == '-');
	if (ne && j < p->width && pa_ch == '0' && !p->minus_flag)
		s++;
	else
		ne = 0;

	if (p->plus_flag && !ne2 && !p->unsign)
		m += _putchar('+'), j++;
	else if (p->space_flag && !ne2 && !p->unsign)
		m += _putchar(' '), j++;
	m += _puts(s);
	while (j++ < p->width)
		m += _putchar(pa_ch);
	return (m);
}
