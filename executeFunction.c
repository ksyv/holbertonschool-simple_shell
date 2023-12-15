#include "shell.h"
/**
 * executeFunction - function that executes the command
 * and his arguments
 * @arg: user's command's argument
 * Return: 0
 */
int executeFunction(char *arg[])
{
	char *_path = NULL;
	char *command = NULL;
	pid_t pid;
	int status;
	int exit_st = 0;

	command = arg[0];
	_path = storedPath(command);
	if (_path == NULL)
	{
		printf("command was not found\n");
		exit_st = WEXITSTATUS(status);
		return (exit_st);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("Error:");
		return (-1);
	}
	if (pid > 0)
		wait(&status);
	else if (pid == 0)
	{
		if (environ)
		{
			execve(_path, arg, environ);
			perror("Error:");
			exit(1);
		}
		else
		{
			execve(_path, arg, NULL);
		}
	}
	free(_path);
	return (0);
}
