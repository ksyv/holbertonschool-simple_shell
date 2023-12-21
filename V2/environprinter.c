#include "shell.h"

/**
 * environPrinter - Prints the environment variables.
 */
void environPrinter(void)
{
	char **actualEnvir = environ;

	while (*actualEnvir != NULL)
	{
		printf("%s\n", *actualEnvir++);
	}
}
