#include "hsh.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int execute_cmd(char **args)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) // child
    {
        if (execve(args[0], args, NULL) == -1)
        {
            perror("hsh");
            exit(EXIT_FAILURE);
        }
    }
    else if (pid < 0) // error
    {
        perror("hsh");
        return (-1);
    }
    else // parent
    {
        waitpid(pid, &status, 0);
    }
    return (status);
}
