#include "shell.h"

/**
 * environPrinter - Prints the environment variables.
 * Return: 0 succes
 */
int environPrinter(void)
{
	char **actualEnvir = environ;

	while (*actualEnvir != NULL)
	{
		printf("%s\n", *actualEnvir++);
	}
	return (0);
}
