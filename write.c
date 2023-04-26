#include "main.h"
#include <stdio.h>

/**
 *_putchar - function to print char
 **ch: character to be printed
 *
 * Return: int
 */

int _putchar(int ch)
{
static int i;
static char buffer[BUF_SIZE];
if (ch == BUF_FLUSH || i >= BUF_SIZE)
{
write(1, buffer, i);
i = 0;
}
if (ch != BUF_FLUSH)
{
buffer[i++] = ch;
}
return (1);
}

/**
 * _puts - print
 * @s: char
 *
 * Return: printed int
 */

int _puts(char *s)
{
char *c = s;
while (*s)
_putchar (*s++);
return (s - c);

}
