#include "simple_shell.h"

int main(void)
{
    char *line;
    int status = 1;

    while (status)
    {
        if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, "($) ", 4);

        line = read_line();

        if (!line)
        {
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            free(line);
            exit(EXIT_SUCCESS);
        }


        status = execute_command(line);
        free(line);
    }

    return EXIT_SUCCESS;
}

