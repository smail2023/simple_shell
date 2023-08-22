#include "shell.h"

/**
 * list_insert - Add node to beginning of linked list
 * @a: head of list
 * @b: Content of node
 * @c: Index of node for history purposes
 * Return: Address of the node
 */
list_t *list_insert(list_t **a, const char *b, int c)
{
list_t *d;
if (!a)
return (NULL);
d = malloc(sizeof(list_t));
if (!d)
return (NULL);
_memset((void *)d, 0, sizeof(list_t));
d->num = c;
if (b)
{
d->str = _strdup(b);
if (!d->str)
{
free(d);
return (NULL);
}
}
d->next = *a;
*a = d;
return (d);
}
/**
 * list_append - Append node to list's tail
 * @a: head of the list
 * @b: Content of new node
 * @c: Index of node for history purposes
 * Return: Address of appended node
 */
list_t *list_append(list_t **a, const char *b, int c)
{
list_t *d, *e;
if (!a)
return (NULL);
e = *a;
d = malloc(sizeof(list_t));
if (!d)
return (NULL);
_memset((void *)d, 0, sizeof(list_t));
d->num = c;
if (b)
{
d->str = _strdup(b);
if (!d->str)
{
free(d);
return (NULL);
}
}
if (e)
{
while (e->next)
e = e->next;
e->next = d;
}
else
*a = d;
return (d);
}
/**
 * list_show - Show 'str' field of each list item
 * @f: Starting node
 * Return: Length of list
 */
size_t list_show(const list_t *f)
{
size_t g = 0;
while (f)
{
_puts(f->str ? f->str : "(nil)");
_puts("\n");
f = f->next;
g++;
}
return (g);
}
/**
 * list_remove - Remove list item by its position
 * @a: head of the list
 * @b: Position of node to be deleted
 * Return: 1 if successful 0 if not
 */
int list_remove(list_t **a, unsigned int b)
{
list_t *d, *e;
unsigned int f = 0;
if (!a || !*a)
return (0);
if (!b)
{
d = *a;
*a = (*a)->next;
free(d->str);
free(d);
return (1);
}
d = *a;
while (d)
{
if (f == b)
{
e->next = d->next;
free(d->str);
free(d);
return (1);
}
f++;
e = d;
d = d->next;
}
return (0);
}
/**
 * list_dispose - Clear all items of list
 * @a: Reference to head of list
 */
void list_dispose(list_t **a)
{
list_t *d, *e, *f;
if (!a || !*a)
return;
f = *a;
d = f;
while (d)
{
e = d->next;
free(d->str);
free(d);
d = e;
}
*a = NULL;
}
