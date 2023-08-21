#include "shell.h"

/**
 * c_pevl - Populates environment linked list.
 * @a: Structure containing potential args
 * Return: Always 0
 */
int c_pevl(info_t *a)
{
list_t *node = NULL;
size_t i;
for (i = 0; environ[i]; i++)
add_node_end(&node, environ[i], 0);
a->env_list = node;
return (0);
}
/**
 * c_gev - Retrieves value of environment var
 * @a: Structure containing potential args
 * @n: Name of the env var
 * Return: value of the specified environment variable
 * or NULL if not found.
 */
char *c_gev(info_t *a, const char *n)
{
list_t *node = a->env_list;
char *v;
while (node)
{
v = starts_with(node->str, n);
if (v && *v)
return (v);
node = node->next;
}
return (NULL);
}
/**
 * c_pe - Prints the current environment
 * @a: Structure containing pot args
 * Return: Always 0
 */
int c_pe(info_t *a)
{
print_list_strings(a->env_list);
return (0);
}
/**
 * c_uev - Removes env variable
 * @a: Structure containing potential arguments
 * Return: Always 0
 */
int c_uev(info_t *a)
{
int i;
if (a->argc == 1)
{
_eputs("Too few arguments.\n");
return (1);
}
for (i = 1; i <= a->argc; i++)
_unsetenv(a, a->argv[i]);
return (0);
}
/**
 * c_sev - Initializes or modifies environment var
 * @a: Structure containing potential arguments
 * Return: Always 0.
 */
int c_sev(info_t *a)
{
if (a->argc != 3)
{
_eputs("Incorrect number of arguments\n");
return (1);
}
if (_setenv(a, a->argv[1], a->argv[2]))
return (0);
return (1);
}

