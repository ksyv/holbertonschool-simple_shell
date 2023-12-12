#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10

int main(void)
{
	char *input;
	char *args[MAX_ARGS];
	int arg_count = 0;
	ssize_t inputLength;
	size_t inputSize = 0;

	if (isatty(STDIN_FILENO)) /*if interactive*/
	{
		while (1)
		{
			printf("$ ");
			inputLength = getline(&input, &inputSize, stdin);
			if (inputLength == -1)
			{
				perror("Error reading input");
				break;
			}
			input[inputLength - 1] = '\0';
			/* divise string with strtok*/

			char *token = strtok(input, " ");

			arg_count = 0;

			while (token != NULL && arg_count < MAX_ARGS - 1)
			{
				args[arg_count] = token;
				arg_count++;
				token = strtok(NULL, " ");
			}
			args[arg_count] = NULL;
			/*run with execvp*/
			if (arg_count > 0)
			{
				pid_t pid = fork();

				if (pid == 0)
				{ /* child process*/
					execve("/bin/sh", args, NULL);
					perror("Error message");
					exit(EXIT_FAILURE);
				}
				else if (pid < 0)
				{ /* fork error*/
					perror("Error processor");
				}
				else
				{				/* parent process */
					wait(NULL); /* wait end of child process */
				}
			}
		}
		return (0);
	}
}
