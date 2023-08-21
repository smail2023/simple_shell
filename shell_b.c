#include "shell.h"

/**
 * a - terminate shell process
 * @b: contain command args
 * Return: status of exit 
 * exits with given exit status (0)
 * if b.argv[0] != "exit"
 */
int a(c *b)
{
int d;
if (!b->argv[1])
{
b->err_num = -1;
return (-2);
}
d = e(b->argv[1]);
if (d == -1)
{
b->status = 2;
f(b, "Invalid number: ");
g(b->argv[1]);
h('\n');
return (1);
}
b->err_num = d;
return (-2);
}
/**
 * i - modify current directory
 * @b: contains command args
 * Return: Always 0
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
l = n(b, "HOME=");
if (!l)
{
l = n(b, "PWD=");
m = chdir(l ? l : "/");
}
else
{
m = chdir(l);
}
}
else if (o(b->argv[1], "-") == 0)
{
l = n(b, "OLDPWD=");
if (l)
{
g(l);
h('\n');
}
else
{
g(k);
h('\n');
return (1);
}
m = chdir(l ? l : "/");
}
else
{
m = chdir(b->argv[1]);
}
if (m == -1)
{
f(b, "Failed to change to directory ");
g(b->argv[1]);
h('\n');
}
else
{
p(b, "OLDPWD", n(b, "PWD="));
p(b, "PWD", getcwd(j, 1024));
}
return (0);
}
/**
 * q - placeholder for help command
 * @b: contains command args
 * Return: Always 0
 */
int q(c *b)
{
char **r = b->argv;
g("Help command is operational but not yet detailed\n");
if (0)
{
g(*r); /* Temporary workaround */
}
return (0);
}

