#include "shell.h"

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *args[MAX_INPUT_SIZE];
    char *token;
    char prompt[] = "#cisfun$ ";
    int status;
    int i;  /* Move the declaration of i here */
    pid_t pid;  /* Move the declaration of pid here */

    while (1)
    {
        printf("%s", prompt);
        fflush(stdout);

        read = getline(&line, &len, stdin);
        if (read == -1)
        {
            printf("\n");
            free(line);
            exit(0);
        }

        i = 0;  /* Initialize i here */
        token = strtok(line, "\n");
        if (token == NULL)
            continue;

        args[i] = token;
        args[i + 1] = NULL;

        pid = fork();  /* Initialize pid here */
        if (pid < 0)
        {
            perror("Fork failed");
            free(line);
            exit(1);
        }
        if (pid == 0)
        {
            if (execve(args[0], args, NULL) == -1)
            {
                printf("./shell: No such file or directory\n");
                free(line);
                exit(1);
            }
        }
        else
        {
            wait(&status);
        }
    }

    free(line);
    return 0;
}

