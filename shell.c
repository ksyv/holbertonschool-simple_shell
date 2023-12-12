#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_ARG_LENGTH 50

int main(void)
{
	char input[MAX_ARG_LENGTH];
	char *args[MAX_ARGS];
	int arg_count = 0;

	if (isatty(STDIN_FILENO)) /*if interactive*/
	{
		while (1)
		{
			printf("$ ");
			fgets(input, sizeof(input), stdin);
			input[strcspn(input, "\n")] = '\0';
			/* divid string with strtok*/

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
					execvp(args[0], args);
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
