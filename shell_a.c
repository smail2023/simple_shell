#include "shell.h"

/**
 * @j: Strg to be converted
 * a_to_b - Convert strg to its integer form
 * Return: Integer representation of strg
 */
int a_to_b(char *j)
{
int y, d = 1, q = 0, g;
unsigned int t = 0;
for (y = 0; j[y] != '\0' && q != 2; y++)
{
if (j[y] == '-')
d *= -1;
if (j[y] >= '0' && j[y] <= '9')
{
q = 1;
t = t * 10 + (j[y] - '0');
}
else if (q == 1)
q = 2;
}
g = (d == -1) ? -t : t;
return (g);
}
/**
 * @e: charr to be checked
 * is_m_char - verify if a char is alphab letter
 * Return: 1 if char is alphabetic 0 if not
 */
int is_m_char(int e)
{
if ((e >= 'a' && e <= 'z') || (e >= 'A' && e <= 'Z'))
return (1);
return (0);
}
/**
 * @u: pointer to struct containing shell info
 * verify_mode - Det if shell is in interactive mode
 * Return: 1 if in interactive mode 0 if not
 */
int verify_mode(info_t *u)
{
return (isatty(STDIN_FILENO) && u->readfd <= 2);
}
/**
 * is_n_delim - check if a given char
 * is part of a delimiter set
 * @z: String containing delimiter chars
 * @e: Char to be checked
 * Return: 1 if character is a delimiter 0 if not
 */
int is_n_delim(char e, char *z)
{
while (*z)
if (*z++ == e)
return (1);
return (0);
}
