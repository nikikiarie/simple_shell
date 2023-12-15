#include  "ni_shell.h"

/**
 * ni_strl - finds string length
 * @a: string
 * Return: int
 */
/*
int ni_strl(char *a)
{
	int i = 0;

	while (*a != '\0')
	{
		i++;
		a++;
	}
	return (i);
}
*/
/**
 * ni_strcpy - copies string
 * @a: dest
 * @z: source
 * Return: pointer
 */
char *ni_strcpy(char *a, char *z)
{
	int i = 0;

	while (*(z + i) != '\0')
	{
		*(a + i) = *(z + i);
		i++;
	}
	*(a + i) = '\0';
	return (a);
}
/**
 * ni_strcmp - compares strings
 * @a: pointer
 * @z: pointer
 * Return: int
 */
int ni_strcmp(const char *a, const char *z)
{
	while (*a && *z && (*a == *z))
	{
		a++;
		z++;
	}
	return (*a - *z);
}
/**
 * ni_strncmp - compares strings
 * @a: string
 * @z: string
 * @i: bytes to compare
 * Return: int
 */
int ni_strncmp(const char *a, const char *z, size_t i)
{
	while (*a && *z && i--)
	{
		if (*a != *z)
			return (*a - *z);
		a++;
		z++;
	}
	if (i == 0)
		return (0);
	else
		return (*a - *z);
}
