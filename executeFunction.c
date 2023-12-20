#include "shell.h"
/**
 * executeFunction - function that executes the command
 * and his arguments
 * @tokenArray: user's command and argument
 * @newPath: path for execute command
 * Return: exit status
 */
int executeFunction(char **tokenArray, char *newPath)
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid < 0)
	{
		perror("./hsh");
		return (EXIT_FAILURE);
	}
	if (pid == 0)
	{
		execve(newPath, tokenArray, environ);
		perror("./hsh");
		exit(EXIT_FAILURE);
	}
	else
	{
		int waitStatus;

		if (waitpid(pid, &waitStatus, 0) == -1)
		{
			perror("./hsh");
			exit(EXIT_FAILURE);
		}
		if (WIFEXITED(waitStatus))
			status = WEXITSTATUS(waitStatus);
		else
		{
			fprintf(stderr, "Child process did not terminate normally\n");
			status = EXIT_FAILURE;
		}
	}
	return (status);
}
