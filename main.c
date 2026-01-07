#include "shell.h"

void execute_command(char **argv)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0)
    {
        execve(argv[0], argv, NULL);
        perror("Error");
        exit(1);
    }
    else
        wait(&status);
}
