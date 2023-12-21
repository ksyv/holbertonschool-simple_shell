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
	int exitStatus = 0;

	command = arg[0];
	_path = storedPath(command);
	if (_path == NULL)
	{
		perror("./hsh");
		exitStatus = WEXITSTATUS(status);
		return (exitStatus);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("./hsh");
		return (EXIT_FAILURE);
	}
	if (pid > 0)
		waitpid(pid, &status, 0);
	else if (pid == 0)
	{
		if (environ)
		{
			execve(_path, arg, environ);
			perror("./hsh");
			exit(1);
		}
		else
		{
			execve(_path, arg, NULL);
		}
	}
	free(_path);
	return (status);
}
