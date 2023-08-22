#include "shell.h"

/**
 * check_argv - Checks if an argument is provided.
 * @b: The structure containing arguments.
 * Return: -2 if no argument is provided, 0 otherwise.
 */
int check_argv(c *b)
{
if (!b->argv[1])
{
b->err_num = -1;
return (-2);
}
return (0);
}
/**
 * convert_arg_to_int - Converts the argument
 * to an integer.
 * @b: The structure containing arguments.
 * Return: -1 if the conversion fails
 * converted integer otherwise.
 */
int convert_arg_to_int(c *b)
{
int d = e(b->argv[1]);
if (d == -1)
{
b->status = 2;
f(b, "Invalid number: ");
g(b->argv[1]);
h('\n');
return (1);
}
b->err_num = d;
return (d);
}
/**
 * a - Validates and converts the argument.
 * @b: The structure containing arguments.
 * Return: Result after validation and conversion.
 */
int a(c *b)
{
int result = check_argv(b);
if (result != 0)
{
return (result);
}
return (convert_arg_to_int(b));
}
/**
 * get_home_directory - Fetches the home directory.
 * @b: The structure containing arguments.
 * Return: Home directory if available, PWD otherwise.
 */
char *get_home_directory(c *b)
{
char *l;
l = n(b, "HOME=");
if (!l)
{
l = n(b, "PWD=");
}
return (l);
}
/**
 * handle_directory - Handles directory change operations.
 * @b: The structure containing arguments.
 * @l: Current directory.
 * Return: Return value after chdir operation.
 */
int handle_directory(c *b, char *l)
{
int m;
if (o(b->argv[1], "-") == 0)
{
l = n(b, "OLDPWD=");
m = chdir(l ? l : "/");
}
else
{
m = chdir(b->argv[1]);
}
return (m);
}
/**
 * i - Implements the 'cd' shell command.
 * @b: The structure containing arguments.
 * Return: 0 on success, other values on errors.
 */
int i(c *b)
{
char j[1024];
char *k = getcwd(j, 1024);
char *l;
int m;
if (!k)
{
g("ERROR: Unable to fetch current directory\n");
}
if (!b->argv[1])
{
l = get_home_directory(b);
m = chdir(l ? l : "/");
}
else
{
m = handle_directory(b, l);
}
}
