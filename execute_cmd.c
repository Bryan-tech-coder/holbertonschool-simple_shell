#include "hsh.h"

/**
 * execute_cmd - executes a command using fork and execve
 * @args: arguments array
 * Return: 0 always
 */
int execute_cmd(char **args)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return (1);
    }
    if (pid == 0)
    {
        if (execve(args[0], args, environ) == -1)
        {
            perror(args[0]);
            _exit(EXIT_FAILURE);
        }
    }
    else
    {
        waitpid(pid, &status, 0);
    }
    return (0);
}
