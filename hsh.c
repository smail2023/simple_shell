#include "simple_shell.h"

int main(void)
{
    char *line = NULL;
    ssize_t read = 0;
    size_t len = 0;

    while (1)
    {
        if (isatty(STDIN_FILENO))
        {
            write(STDOUT_FILENO, "($) ", 4);
            fflush(stdout);  /* Ensure the buffer is flushed after the write. */
        }
        
        read = getline(&line, &len, stdin);

        if (read == -1)
        {
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            free(line);
            exit(EXIT_SUCCESS);
        }

        execute_command(line);
        free(line);
    }

    return 0;
}

