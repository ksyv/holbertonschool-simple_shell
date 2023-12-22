#include "shell.h"
/**
 * *_strdup - copy a given string and return pointer
 *  @str: the string
 *  Return: the adress of the new string
 */
char *_strdup(char *str)
{
	char *st = NULL;
	int i;

	if (str == NULL)
		return (NULL);
	for (i = 0; str[i]; i++)
		continue;
	st = malloc((i + 1) * sizeof(char));
	if (st == NULL)
		return (NULL);
	for (i = 0; str[i]; i++)
		st[i] = str[i];
	return (st);
}
