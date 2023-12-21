#include "shell.h"
/**
 * storedPath - function that looks for the command path
 * @command: command
 * Return: the path
 */
char *storedPath(char *command)
{
	int index = 0;
	char *path = NULL, *pathToken = NULL;
	char *pathArray[1000];
	char *newPath = NULL;
	struct stat buf;

	path = strdup(getenv("PATH")); /* gets a dup of PATH */
	pathToken = strtok(path, ":"); /* split the path in a set of tokens */
	newPath = (char *) malloc(sizeof(char) * 1024);
	if (stat(command, &buf) == 0)
	{
		strcpy(path, command);
		return (path); /* return a copy of command */
	}
	while (pathToken != NULL)
	{
		pathArray[index] = pathToken; /* store results of tokens in path_array */
		index++;
		pathToken = strtok(NULL, ":");
	}
	index = 0;
	while (pathArray[index] != NULL)
	{
		strcpy(newPath, pathArray[index]); /* copy tokens to new path */
		strcat(newPath, "/"); /* add "/" and command */
		strcat(newPath, command);
		strcat(newPath, "\0");
		if (stat(newPath, &buf) == 0) /* if sucess, free and return new_path */
		{
			free(path);
			return (newPath);
		}
		index++;
	}
	free(path);
	free(newPath);
	return (NULL);/* in case of possible errors */
}
