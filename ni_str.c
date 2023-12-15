#include "ni_shell.h"
/**
 * ni_strlen - returns str length
 * @s: string
 * Return: int
 */
size_t ni_strln(const char *s)
{
	size_t i = 0;

	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}
/**
 * ni_getenv - fetch env
 * @a: env
 * Return: pointer to env
 */
char *ni_getenv(const char *a)
{
	size_t l = ni_strln(a);
	char **env = environ;

	for (; *env != NULL; env++)
	{
		if (ni_strncmp(a, *env, l) == 0 && (*env)[l] == '=')
			return (&((*env)[l + 1]));
	}
	return (NULL);
}
