#include "shell.h"

/**
 * a_to_b - Convert string to its integer form
 * @j: String to be converted
 * Return: Integer representation of string
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
 * is_m_char - Verify if a character is an alphabetic letter
 * @e: Character to be checked
 * Return: 1 if character is alphabetic, 0 if not
 */
int is_m_char(int e)
{
if ((e >= 'a' && e <= 'z') || (e >= 'A' && e <= 'Z'))
return (1);
return (0);
}
/**
 * verify_mode - Determine if shell is in interactive mode
 * @u: Pointer to struct containing shell info
 * Return: 1 if in interactive mode, 0 if not
 */
int verify_mode(info_t *u)
{
return (isatty(STDIN_FILENO) && u->readfd <= 2);
}
/**
 * is_n_delim - Check if a given character is part of a delimiter set
 * @z: String containing delimiter characters
 * @e: Character to be checked
 * Return: 1 if character is a delimiter, 0 if not
 */
int is_n_delim(char e, char *z)
{
while (*z)
if (*z++ == e)
return (1);
return (0);
}
