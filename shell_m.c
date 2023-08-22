#include "shell.h"

/**
 * get_length - Determine length of linked list
 * @n: Pointer to first node
 * Return: Size of list
 */
size_t get_length(const list_t *n)
{
size_t len = 0;
while (n)
{
n = n->next;
len++;
}
return (len);
}
/**
 * extract_strings - Convert linked list content to array of strings
 * @h: Pointer to first node
 * Return: Array of strings
 */
char **extract_strings(list_t *h)
{
list_t *node = h;
size_t len = get_length(h), i;
char **strings;
char *string;
if (!h || !len)
return (NULL);
strings = malloc(sizeof(char *) * (len + 1));
if (!strings)
return (NULL);
for (i = 0; node; node = node->next, i++)
{
string = malloc(_strlen(node->str) + 1);
if (!string)
{
for (size_t j = 0; j < i; j++)
free(strings[j]);
free(strings);
return (NULL);
}
string = _strcpy(string, node->str);
strings[i] = string;
}
strings[i] = NULL;
return (strings);
}
/**
 * display_list - Print elements of list_t linked list
 * @n: Pointer to first node
 * Return: Size of list
 */
size_t display_list(const list_t *n)
{
size_t len = 0;
while (n)
{
_puts(convert_number(n->num, 10, 0));
_putchar(':');
_putchar(' ');
_puts(n->str ? n->str : "(nil)");
_puts("\n");
n = n->next;
len++;
}
return (len);
}
/**
 * find_node_with_prefix - Find node who
 * string starts with prefix
 * @node: Pointer to list head
 * @prefix: String to match
 * @c: next char after prefix to match
 * Return: Matching node or NULL.
 */
list_t *find_node_with_prefix(list_t *node, char *prefix, char c)
{
char *p = NULL;
while (node)
{
p = starts_with(node->str, prefix);
if (p && ((c == -1) || (*p == c)))
return (node);
node = node->next;
}
return (NULL);
}
/**
 * get_node_position - Get index of node
 * @head: Pointer to list head
 * @node: Pointer to node
 * Return: Index of node or -1.
 */
ssize_t get_node_position(list_t *head, list_t *node)
{
size_t pos = 0;
while (head)
{
if (head == node)
return (pos);
head = head->next;
pos++;
}
return (-1);
}
