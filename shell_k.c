#include "shell.h"

/**
 * a - Constructs allocated string 
 * containing history file's path
 * @b: Structure holding context
 * Return: Allocated string with history 
 * file path or NULL on failure
 */
char *a(b_t *b)
{
char *c, *d;
d = _getenv(b, "HOME=");
if (!d)
return (NULL);
c = malloc(sizeof(char) * (_strlen(d) + _strlen(HIST_FILE) + 2));
if (!c)
return (NULL);
c[0] = 0;
_strcpy(c, d);
_strcat(c, "/");
_strcat(c, HIST_FILE);
return (c);
}
/**
 * e - Inserts entry into history linked list
 * @b: Context structure
 * @c: buffer holding history data
 * @f: Counter for history lines
 * Return: Always 0
 */
int e(b_t *b, char *c, int f)
{
list_t *g = NULL;
if (b->history)
g = b->history;
add_node_end(&g, c, f);
if (!b->history)
b->history = g;
return (0);
}
/**
 * h - Updates numbering of history items after changes
 * @b: Structure providing context
 * Return: Updated count of history items
 */
int h(b_t *b)
{
list_t *g = b->history;
int i = 0;
while (g)
{
g->num = i++;
g = g->next;
}
return (b->histcount = i);
}
/**
 * i - Saves current history to file
 * @b: Structure holding context.
 * Return: 1 if successful -1 if not
 */
int i(b_t *b)
{
ssize_t j;
char *k = a(b);
list_t *g = NULL;
if (!k)
return (-1);
j = open(k, O_CREAT | O_TRUNC | O_RDWR, 0644);
free(k);
if (j == -1)
return (-1);
for (g = b->history; g; g = g->next)
{
_putsfd(g->str, j);
_putfd('\n', j);
}
_putfd(BUF_FLUSH, j);
close(j);
return (1);
}
/**
 * l - Populates history from saved file
 * @b: Structure holding context
 * Return: Total history items if successful 0 if not
 */
int l(b_t *b)
{
int m, n = 0, o = 0;
ssize_t j, p, q = 0;
struct stat r;
char *s = NULL, *k = a(b);
if (!k)
return (0);
j = open(k, O_RDONLY);
free(k);
if (j == -1)
return (0);
if (!fstat(j, &r))
q = r.st_size;
if (q < 2)
return (0);
s = malloc(sizeof(char) * (q + 1));
if (!s)
return (0);
p = read(j, s, q);
s[q] = 0;
if (p <= 0)
return (free(s), 0);
close(j);
for (m = 0; m < q; m++)
if (s[m] == '\n')
{
s[m] = 0;
e(b, s + n, o++);
n = m + 1;
}
if (n != m)
e(b, s + n, o++);
free(s);
b->histcount = o;
while (b->histcount-- >= HIST_MAX)
delete_node_at_index(&(b->history), 0);
h(b);
return (b->histcount);
}

