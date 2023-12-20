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
		waitpid(pid, &status, 0);
	return (status);
}
