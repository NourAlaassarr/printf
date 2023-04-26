#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 *getflag - function to intialize flags
 *@c: character
 *@p: parameter to struct
 *Return: number of flags
 */

int getflag(char *c, params_ *p)
{
	int flag = 0;
	switch (*c)
	{
		case '+':
			flag = p->plus_flag = 1;
		        break;
		case '-':
			flag = p->minus_flag = 1;
			break;
		case '#':
			flag = p->hashtag_flag = 1;
			break;
		case ' ':
			flag = p->space_flag = 1;
			break;
		case '0':
			flag = p->zero_flag = 1;
			break;
		default:
			printf("Unknowen option: %\n", *c);
			return (0);
		}
	return (flag);

/**
 * getwidth - function to get width
 * @c: string
 * @p: the parameter struct
 * @ptr: pointer
 *
 * Return - pointer
 */

int *getwidth(char *c, params_ *p, va_list ptr)
{
	int width = 0;
	if (*c == '*')
	{
		width = va_arg(p, int);
		c++;
	}
	else
	{
		while (isdigit_(*c))
			width *= 10 + (*c++ - '0');
	}
	p->width = width;
	return (c);
}

/**
 * getmodifier - find modifier is it long or short
 * @c: string
 * @p: parameter to struct
 *
 * Return: modifer if available
 */

int getmodifier(char *c, params_ *p)
{
	int mod = 0;
	switch (*c)
	{
		case 'h':
			mod = p->hmodifier = 1;
			break;
		case 'l':
			mod = p->lmodifier = 1;
			break;
	}
	return (mod);
}
