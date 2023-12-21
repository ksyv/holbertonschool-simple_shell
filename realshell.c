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
	int status = 0;
	int exitstatus = 0;
	char *new_path = NULL;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1) /* if interactive */
			printf("$ ");			   /*print prompt*/
		inputLine = getline(&input, &inputSize, stdin);
		if (inputLine == -1)
		{
			if (isatty(STDIN_FILENO) == 1)
				printf("\n");
			break;
		}
		input[inputLine - 1] = '\0';/*replace line jump by end of string*/
		if (tokeniseCommand(input, inputLine) == 2)/* in case of exit */
			break;
		freeall(input, new_path);
		inputSize = 0;
	}
	freeall(input, new_path);
	exitstatus = WEXITSTATUS(status);
	return (exitstatus);
}
