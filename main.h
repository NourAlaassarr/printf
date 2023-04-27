#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define LONG_N 2
#define SHORT_N 1

#define MINUS_FLAG 1
#define PLUS_FLAG 2
#define ZERO_FLAG 4
#define HASHTAG_FLAG 8
#define SPACE_FLAG 16

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;


/* _printf main function */
int _printf(const char *format, ...);
void print_buffer(char buff[], int *buff_ind);
int handle_print(const char *fmt, int *i,
va_list list, char buff[], int flags, int width, int precision, int size);



/* Funtions to print chars and strings */
int print_characters(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list ptr, char arr[],
	int flag, int wid, int precision, int s);
int percent_print(va_list ptr, char arr[],
	int flag, int wid, int precision, int s);

/* functions to print number */
int int_print(va_list types, char buff[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buff[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buff[],
	int flags, int width, int precision, int size);
int print_octal(va_list types, char buff[],
	int flags, int width, int precision, int size);
int print_hex(va_list types, char buff[],
	int flags, int width, int precision, int size);
int print_HEX(va_list types, char buff[],
	int flags, int width, int precision, int size);
int print_hexanum(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int non_print(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funcion to print memory address */
int print_address(va_list ptr, char bfr[],
	int flag, int w, int pre, int sz);

/* Funciotns to handle other specifiers */
int getflag(const char *format, int *f);
int getwidth(const char *format, int *w, va_list ptr);
int getprecision(const char *format, int *p, va_list ptr);
int getsize(const char *format, int *s);

/* Function to print string in reverse */
int print_reverse(va_list ptr, char bfr[], int flag, int w, int pre, int sz);

/* Function to print a string in rot 13 done */
int print_rotation(va_list ptr, char bfr[],
	int flag, int w, int pre, int sz);

/* width handler */
int write_characters(char c, char buffer[],
	int flags, int width, int precision, int size);
int pointer_writing(char bfr[], int ind, int len,
	int w, int flag, char padding, char extra, int p_start);
int write_unsigned(int negative, int x,
		char *bfr, int flag, int w, int p, int s);
int write_numb(int ispos, int ind, char bfr[],
	int flag, int w, int pre, int sz);
int number_writing(int ind, char bfr[], int flag, int w, int prec,
	int l, char padd, char extra);


/* helping functions */
int checkifprintable(char p);
int hexa_appened(char asci, char arr[], int j);
int isdigit_(char numb);
long int converting_num(long int n, int s);
long int converting_unsign(unsigned long int n, int s);

#endif /* _PRINTF_H */
