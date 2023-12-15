#include "shell.h"
/**
 * _getenv - retrieves an env variable from the environment
 * @name: the name of the var
 * Return: the value stored in the var or NULL on failure
 */
char *_getenv(char *name)
{
	int i = 0;
	char *env_var;

	while (environ[i] != NULL)
	{
		if (_strncmp(environ[i], name, _strlen(name)) == 0)
		{
			env_var = &environ[i][_strlen(name) + 1];
			return (env_var);
		}
		i = i + 1;
	}
	return (NULL);
}
/**
 * _strcat - concatenates two strings
 * @s1: string would be copied.
 * @s2: target
 * Return: pointer to dest
 */
char *_strcat(char *s1, char *s2)
{
	int i;

	i = _strlen(s1);
	while (*s2 != '\0')
	{
		s1[i] = *s2;
		i++;
		s2++;
	}
	s1[i] = '\0';
	return (s1);
}
/**
 * _strlen - returns the length of a string
 * @s: variable insert
 * Return: number of characters
 */
int _strlen(char *s)
{
	int ns = 0, p = 0;

	while (s[p] != 0)
	{
		ns++;
		p++;
	}
	return (ns);
}
/**
 * _strcpy - copies the string pointed to by src,
 * including the terminating null byte (\0), to the buffer pointed to by dest
 * @dest: string of destination
 * @src: string copied
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int t = 0;

	while (*(src + t) != '\0')
	{
		*(dest + t) = *(src + t);
		t++;
	}
	*(dest + t) = *(src + t);
	return (dest);
}
/**
 * _strncmp - compares 2 string
 * @s1: first string
 * @s2: second string
 * @n: size of string who compareted
 * Return: 0 if the twice are equal,
 * positif if the first is greater,
 * negatif if the first is smaller.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		if (i < (n - 1))
			i++;
		else
			return (0);
	}
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}
