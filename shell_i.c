#include "shell.h"

/**
 * A - Updates new environment variable
 * @B: Contains pot arguments to ensure
 * constant function prototype
 * @C: environment variable's identifier
 * @D: value to be assigned to environment variable
 * Return: Always 0
 */
int A(B_t *B, char *C, char *D)
{
char *E = NULL;
node_t *F;
char *G;
if (!C || !D)
return (0);
E = malloc(_strlen(C) + _strlen(D) + 2);
if (!E)
return (1);
_strcpy(E, C);
_strcat(E, "=");
_strcat(E, D);
F = B->env;
while (F)
{
G = starts_with(F->str, C);
if (G && *G == '=')
{
free(F->str);
F->str = E;
B->env_changed = 1;
return (0);
}
F = F->next;
}
add_node_end(&(B->env), E, 0);
free(E);
B->env_changed = 1;
return (0);
}
/**
 * H - Erases specific environment variable
 * @B: Contains poten arguments to ensure
 * constant function prototype
 * @C: Identifier of environment variable to be removed
 * Return: 1 if deleted 0 if not
 */
int H(B_t *B, char *C)
{
node_t *F = B->env;
size_t I = 0;
char *G;
if (!F || !C)
return (0);
while (F)
{
G = starts_with(F->str, C);
if (G && *G == '=')
{
B->env_changed = delete_node_at_index(&(B->env), I);
I = 0;
F = B->env;
continue;
}
F = F->next;
I++;
}
return (B->env_changed);
}
/**
 * J - Provides strgn array copy of environment
 * @B: Contains potential arguments to ensure
 * constant function prototype
 * Return: Pointer to environment string array
 */
char **J(B_t *B)
{
if (!B->environ || B->env_changed)
{
B->environ = list_to_strings(B->env);
B->env_changed = 0;
}
return (B->environ);
}
