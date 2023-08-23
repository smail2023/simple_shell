#include "simple_shell.h"

char *read_line(void)
{
    char *line = NULL;
    size_t len = 0;
    getline(&line, &len, stdin);
    return line;
}

int check_exit(char *command)
{
    if (strncmp(command, "exit", 4) == 0)
        return 1;
    return 0;
}

int execute_command(char *command)
{
    pid_t pid;
    int status;
    char *args[2];

    if (check_exit(command))
        exit(EXIT_SUCCESS);

    args[0] = strtok(command, "\n\t\r ");  /* Just tokenize once to get the command */
    args[1] = NULL;  /* No arguments passed */

    pid = fork();
    if (pid == 0)
    {
        if (execve(args[0], args, environ) == -1)  /* Using environ here */
        {
            perror(args[0]);
            exit(EXIT_FAILURE);
        }
    }
    else if (pid < 0)
    {
        perror("./hsh");
    }
    else
    {
        do
        {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

