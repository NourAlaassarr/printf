#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

/**
 * add_param - function to add default numb to each parameter
 * @par: parameter from struct
 * @ptr: pointer
 *
 * Return - void
 */

void add_param(params_ *par, va_list ptr)
{
	par->minus_flag = 0;
	par->plus_flag = 0;
	par->space_flag = 0;
	par->hashtag_flag = 0;
	par->zero_flag = 0;
	par->width = 0;
	par->precision = UNIT_MAX;
	par->lmodifier = 0;
	par->hmodifier = 0;
	(void)ptr;
}
