#include "hsh.h"

/**
 * execute_cmd - Execute command using fork and execve
 * @argv: Tokenized arguments
 */
void execute_cmd(char **argv)
{
	pid_t pid;
	int status;

	if (!argv || !argv[0])
		return;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return;
	}
	if (pid == 0)
	{
		if (execvp(argv[0], argv) == -1)
		{
			perror("hsh");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
