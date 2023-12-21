#include "shell.h"
/**
 * storedPath - function that looks for the command path
 * @command: command
 * Return: the path
 */
char *storedPath(char *command)
{
	char *path = strdup(_getenv("PATH"));
	char *tokens = strtok(path, ":");
	struct stat buf;
	char *new_path = NULL;
	size_t path_len = 0, command_len = 0;
	size_t new_path_size = 0;

	if (path == NULL)
	{
		perror("_getenv(PATH) failed");
		return (NULL);
	}
	while (tokens != NULL)
	{
		path_len = strlen(tokens);
		command_len = strlen(command);
		new_path_size = path_len + command_len + 2;

		new_path = malloc(new_path_size);
		if (new_path == NULL)
		{
			perror("Memory allocation failed");
			free(path);
			return (NULL);
		}
		strcpy(new_path, tokens);
		strcat(new_path, "/");
		strcat(new_path, command);
		if (stat(new_path, &buf) == 0)
		{
			free(path);
			return (new_path);
		}
		free(new_path);
		tokens = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}
