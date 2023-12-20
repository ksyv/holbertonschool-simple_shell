#include "shell.h"
/**
 * main - command interpreter
 * Return: 0
 */
int main(void)
{
	char *input = NULL;
	ssize_t inputLine = 0;
	int status = 0;
	int exitstatus = 0;
	char *new_path = NULL;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1) /* if interactive */
			printf("$ ");			   /*print prompt*/
		input = inputFunction();
		if (tokeniseCommand(input, inputLine) == 2)/* in case of exit */
			break;
		freeall(input, new_path);
		input = NULL;
		new_path = NULL;
	}

	freeall(input, new_path);
	input = NULL;
	new_path = NULL;
	exitstatus = WEXITSTATUS(status);
	return (exitstatus);
}
