#include "simple_shell.h"
extern char **environ;

char *read_line(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read = getline(&line, &len, stdin);
    
    if (read == -1)
    {
        free(line);
        return NULL;
    }
    
    return line;
}

int execute_command(char *command)
{
    pid_t pid;
    int status;

    if (strncmp(command, "exit", 4) == 0)
    {
        free(command);
        exit(EXIT_SUCCESS);
    }

    pid = fork();
    if (pid == 0)
    {
        char *args[2];
        args[0] = strtok(command, "\n\t\r ");  /* Get the command */
        args[1] = NULL;  /* No arguments passed */
        

        if (execve(args[0], args, environ) == -1)
        {
            perror(args[0]);
            exit(EXIT_FAILURE);
        }
    }
    else if (pid < 0)
    {
        perror("hsh");
    }
    else
    {
        waitpid(pid, &status, WUNTRACED);
    }

    return 1;
}

