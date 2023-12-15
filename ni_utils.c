#include "ni_shell.h"
/**
 * ni_strtok - returns string in tokens
 * @s: string
 * @d: delimeter pointer
 * Return: pointer
 */
char *ni_strtok(char *s, const char *d)
{
	char *tkn;
	static char *n;

	if (s != NULL)
		n = s;
	tkn = n;
	if (tkn == NULL)
		return (NULL);
	tkn += ni_strspn(tkn, d);
	if (*tkn == '\0')
	{
		n = NULL;
		return (NULL);
	}
	n = tkn + ni_strcspn(tkn, d);
	if (*n != '\0')
	{
		*n = '\0';
		n++;
	}
	return (tkn);
}
/**
 * ni_strcspn - rturns length of string
 * @p: pointer to string
 * @z: reject
 * Return: int
 */
size_t ni_strcspn(const char *p, const char *z)
{
	size_t i = 0;

	while (*p)
	{
		if (ni_strchr(z, *p))
			return (i);
		else
			p++, i++;
	}
	return (i);
}
/**
 * ni_strchr - searches for 1st 'c' to occur
 * @c: character
 * @i: int
 * Return: pointer
 */
char *ni_strchr(const char *c, int i)
{
	while (*c != '\0')
	{
		if (*c == 'c')
			return ((char *)c);
		c++;
	}
	if (i == '\0')
		return ((char *)c);
	return (NULL);
}
/*	size_t ni_strcspn(const char *p, const char *z*/
/**
 * ni_strspn - finds char not delimeted
 * @s: character string
 * @d: delimeter
 * Return: length of string
 */
size_t ni_strspn(const char *s, const char *d)
{
	size_t a = 0;
	int b;

	while (s[a] != '\0')
	{
		b = 0;
		while (d[b] != '\0')
		{
			if (s[a] == d[b])
				break;
			b++;
		}
		if (d[b] == '\0')
			break;
		a++;
	}
	return (a);
}
/**
 * ni_strl - finds string length
 * @a: string
 * Return: int
 */
int ni_strlen(char *a)
{
	int i = 0;

	while (*a != '\0')
	{
		i++;
		a++;
	}
	return (i);
}
