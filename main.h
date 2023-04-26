#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>

#define NULL_STRING "(null)"
#define ADD_PARAM {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define BUF_FLUSH -1
#define BUF_SIZE 1024
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/**
*struct parameters - struct containing parameters
*
*@unsigned: flag

*@plus_flag:flag
*@minus_flag:flag
*@space_flag:flag
*@hashtag_flag:flag
*@zero_flag:flag

*@width:flag
*@precision:flag

*@lmodifier:flag
*@hmodifier:flag
*/
typedef struct parameters
{
	unsigned int unsign : 1;
	unsigned int plus_flag : 1;
	unsigned int space_flag : 1;
	unsigned int zero_flag : 1;
	unsigned int minus_flag : 1;
	unsigned int width;
	unsigned int precision;
	unsigned int hashtag_flag : 1;
	unsigned int lmodifier : 1;
	unsigned int hmodifier : 1;
}params_;
/**
*struct specifier - struct

*@speci: format
*@s:the function
*/
typedef struct specifier
{
	char *speci;
	int (*s)(va_list, params_);
}specifier_;

/*_put.c*/
int _putchar(int ch);
int _puts(char *s);

/*stringfunction.c*/
int print_characters(va_list ptr, params_ *p);
int print_string(va_list ptr, params_ *p);
int percent_print(va_list ptr, params_ *p);
int print_S(va_list ptr, params_ *p);
int int_print(va_list ptr, params_ *p);

/*getspecifier.c*/
int (*get_type(char *s))(va_list ptr, params_ *p);

/*getter.c*/
int getflag(char *c, params_ *p);
char *getwidth(char *c, params_ *p, va_list ptr);

/*parameters.c*/
void add_param(params_ *par, va_list ptr);

/*numberhandling.c*/
int print_hex(va_list ap, params_ *p);
int print_HEX(va_list ap, params_ *p);
int print_binary(va_list ap, params_ *p);
int print_octal(va_list ap, params_ *p);
int int_print(va_list ap, params_ *p);

/*printtohandle.c*/
int print_all(char* beg, char *last, char *not);
int print_reverse(va_list ap, params_ *p);
int print_rotation(va_list ap, params_ *p);
int print_function(char *c, va_list p, params_ *parameters);

/*functions.c*/
int print_address(va_list ap, params_ *p);
int print_unsigned(va_list ap, params_ *p);
char *converting(long int number, int base, int flags, params_ *p);

/*printf.c*/
int _printf(const char *format, ...);

/*percision.c*/
char *getprecision(char*c, params_ *p, va_list ptr);

/*helpingfunctions.c*/
int isdigit_(int numb);
int strlength(char *str);
int printnumbers(char *s, params_ *p);
int print_right_shift(char *s, params_ *p);
int print_left_shift(char *s, params_ *p);

#endif /*_PRINTF_H*/
