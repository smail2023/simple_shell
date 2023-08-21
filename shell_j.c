#include "shell.h"

/**
 * h - Setups b fields based on command input
 * @b: Pointer to data structure
 * @i: List of arguments
 */
void h(c *b, char **i)
{
int j = 0;
b->k = i[0];
if (b->d)
{
b->e = tokenize(b->d, " \t");
if (!b->e)
{
b->e = malloc(sizeof(char *) * 2);
if (b->e)
{
b->e[0] = _strdup(b->d);
b->e[1] = NULL;
}
}
for (j = 0; b->e && b->e[j]; j++)
;
b->g = j;
l(b);
m(b);
}
}
/**
 * a - Resets b fields
 * @b: Pointer to data structure
 */
void a(c *b)
{
b->d = NULL;
b->e = NULL;
b->f = NULL;
b->g = 0;
}
/**
 * n - Releases memory held by b fields
 * @b: Pointer to data structure
 * @o: Flag to indicate if all fields should be freed
 */
void n(c *b, int o)
{
ffree(b->e);
b->e = NULL;
b->f = NULL;
if (o)
{
if (!b->p)
free(b->d);
if (b->q)
free_list(&(b->q));
if (b->r)
free_list(&(b->r));
if (b->s)
free_list(&(b->s));
ffree(b->t);
b->t = NULL;
bfree((void **)b->p);
if (b->u > 2)
close(b->u);
_putchar(BUF_FLUSH);
}
}
