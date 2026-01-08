#include "hsh.h"

/**
 * tokenize - splits line into arguments
 * @line: input line
 *
 * Return: array of arguments
 */
char **tokenize(char *line)
{
	char **argv;
	char *token;
	int i = 0;

	argv = malloc(sizeof(char *) * 64);
	if (!argv)
		return (NULL);

	token = strtok(line, " \t\n");
	while (token)
	{
		argv[i++] = token;
		token = strtok(NULL, " \t\n");
	}
	argv[i] = NULL;

	return (argv);
}

/**
 * execute_cmd - executes a command
 * @argv: argument vector
 */
void execute_cmd(char **argv)
{
	if (execve(argv[0], argv, environ) == -1)
	{
		perror(argv[0]);
		exit(1);
	}
}

/**
 * shell_loop - main shell loop
 */
void shell_loop(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **argv;
	pid_t pid;
	int status;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			free(line);
			exit(0);
		}

		argv = tokenize(line);
		if (!argv || !argv[0])
		{
			free(argv);
			continue;
		}

		pid = fork();
		if (pid == 0)
			execute_cmd(argv);
		else
			wait(&status);

		free(argv);
	}
}
