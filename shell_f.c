#include "shell.h"
/**
 * stringCopy - Duplicates part of strg
 * @x: Target strgn
 * @y: Source strgn
 * @z: Number of characters to be copied
 * Return: Pointer to target strg
 */
char *stringCopy(char *x, char *y, int z)
{
int p, q;
char *r = x;
p = 0;
while (y[p] != '\0' && p < z - 1)
{
x[p] = y[p];
p++;
}
if (p < z)
{
q = p;
while (q < z)
{
x[q] = '\0';
q++;
}
}
return (r);
}
/**
 * findChar - Finds first occurrence of char in strg
 * @m: String to search
 * @n: Character to find
 * Return: Pointer to first occurrence or NULL if not found.
 */
char *findChar(char *m, char n)
{
do 
{
if (*m == n)
return (m);
} while (*m++ != '\0');
return (NULL);
}
/**
 * concatenateStrings - Joins two strgs to given number of chars
 * @s: Target string
 * @t: Source string
 * @u: Maximum number of chars
 * Return: Pointer to target strg
 */
char *concatenateStrings(char *s, char *t, int u)
{
int v, w;
char *o = s;
v = 0;
w = 0;
while (s[v] != '\0')
v++;
while (t[w] != '\0' && w < u)
{
s[v] = t[w];
v++;
w++;
}
if (w < u)
s[v] = '\0';
return (o);
}
