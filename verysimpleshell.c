#include "shell.h"
/**
 * main - command interpreter
 * Return: 0
 */
int main(void)
{
	char *input = NULL;
	size_t inputSize = 0;
	ssize_t inputLine = 0;
	char *args[2];
	pid_t pid;
	int status;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1) /* if interactive */
			printf("$ ");			   /*print prompt*/

		inputLine = getline(&input, &inputSize, stdin);
		if (inputLine == -1)
		{
			perror("./hsh");
		}
		input[inputLine - 1] = '\0'; /*replace line jump by end of string*/
		args[0] = input;
		args[1] = NULL;
		/* Create a child process*/
		pid = fork();

		if (pid == -1)
		{
			perror("./hsh");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			/*Child process*/
			if (execve(args[0], args, environ) == -1)
			{
				perror("./hsh");
				free(input);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			/* Parent process*/
			waitpid(pid, &status, 0);
		}
	}
	free(input);
	return (0);
}
