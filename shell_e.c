#include "shell.h"

/**
 * _cputc - Writes a character to standard error
 * @ch: The character to print
 * Return: On success, returns 1
 * On error, returns -1
 */
int _cputc(char ch)
{
static int i;
static char buf[WRITE_BUF_SIZE];
if (ch == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(2, buf, i);
i = 0;
}
if (ch != BUF_FLUSH)
buf[i++] = ch;
return (1);
}
/**
 * _e - prints input string to standard error
 * @s: string to be printed
 * Return: Nothing
 */
void _e(char *s)
{
int i = 0;
if (!s)
return;
while (s[i] != '\0')
{
_cputc(s[i]);
i++;
}
}
/**
 * _c - Writes a char to given file descriptor
 * @c: character to print
 * @fd: file descriptor to write to
 * Return: On success returns 1
 * On error returns -1 and sets errno
 */
int _c(char c, int fd)
{
static int i;
static char buf[WRITE_BUF_SIZE];
if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(fd, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}
/**
 * _p - Prints input string to given file descriptor
 * @s: string to be printed
 * @fd: file descriptor to write
 * Return: number of characters written
 */
int _p(char *s, int fd)
{
int i = 0;
if (!s)
return (0);
while (*s)
{
i += _c(*s++, fd);
}
return (i);
}
