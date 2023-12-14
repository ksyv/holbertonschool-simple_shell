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
 * @src: string would be copied.
 * @dest: target
 * Return: pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	int t1 = 0, t2 = 0;

	while (*(dest + t1) != '\0')
	{
		t1++;
	}
	while (*(src + t2) != '\0')
	{
		*(dest + t1) = *(src + t2);
		t1++;
		t2++;
	}
	return (dest);
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
 * _strncpy - copies a string
 * @dest: string of destination
 * @src: string copied
 * @n: maximum bytes copied
 * Return: pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int t = 0;

	while (*(src + t) != '\0' && t < n)
	{
		*(dest + t) = *(src + t);
		t++;
	}
	if (t < n)
	{
		*(dest + t) = *(src + t);
		t++;
		while (t < n)
		{
			*(dest + t) = '\0';
			t++;
		}
	}
	return (dest);
}
/**
 * _strcmp - compares 2 string
 * @s1: first string
 * @s2: second string
 * Return: 0 if the twice are equal,
 * positif if the first is greater,
 * negatif if the first is smaller.
 */
int _strcmp(char *s1, char *s2)
{
	int t = 0, r = 0;

	while (*(s1 + t) != '\0' && *(s2 + t) != '\0')
	{
		if (*(s1 + t) > *(s2 + t))
		{
			r += *(s1 + t) - *(s2 + t);
			return (r);
		}
		if (*(s1 + t) < *(s2 + t))
		{
			r -= *(s2 + t) - *(s1 + t);
			return (r);
		}
		t++;
	}
	return (r);
}
