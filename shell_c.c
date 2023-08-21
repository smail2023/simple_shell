#include "shell.h"

/**
 * h - Prints command history with line numbers
 * @d: Pointer to structure contains history data
 * Return: 0
 */
int h(info_t *d)
{
print_list(d->history);
return (0);
}
/**
 * d - Displays content of alias node
 * @a: alias node
 * Return: 0 if alias node exists 1 if not
 */
int d(list_t *a)
{
char *e = NULL, *s = NULL;
if (a)
{
e = _strchr(a->str, '=');
for (s = a->str; s <= e; s++)
__putchar(*s);
__putchar('\'');
_puts(e + 1);
_puts("'\n");
return (0);
}
return (1);
}
/**
 * m - Manages alias commands
 * @d: Pointer to structure
 * Return: 0
 */
int m(info_t *d)
{
int n = 0;
char *e = NULL;
list_t *a = NULL;
if (d->argc == 1)
{
a = d->alias;
while (a)
{
d(a);
a = a->next;
}
return (0);
}
for (n = 1; d->argv[n]; n++)
{
e = _strchr(d->argv[n], '=');
if (e)
a(d, d->argv[n]);
else
d(node_starts_with(d->alias, d->argv[n], '='));
}
return (0);
}
/**
 * r - Removes alias based on strg
 * @d: Pointer containing alias data
 * @a: alias string
 * Return: 0 if success 1 if not
 */
int r(info_t *d, char *a)
{
char t, *e;
int o;
e = _strchr(a, '=');
if (!e)
return (1);
t = *e;
*e = 0;
o = delete_node_at_index(&(d->alias), get_node_index(d->alias, node_starts_with(d->alias, a, -1)));
*e = t;
return (o);
}
/**
 * a - updates alias
 * @d: Pointer containing alias data
 * @a: alias string 
 * Return: 0 if succeeded 1 if not
 */
int a(info_t *d, char *a)
{
char *e;
e = _strchr(a, '=');
if (!e)
return (1);
if (!*++e)
return (r(d, a));
r(d, a);
return (add_node_end(&(d->alias), a, 0) == NULL);
}
