#include "shell.h"

/**
 **_strncpy - copies a string
 *@dest: the destination string to be copied to
 *@src: the source string
 *@n: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int ii, jj;
	char *s = dest;

	ii = 0;
	while (src[ii] != '\0' && ii < n - 1)
	{
		dest[ii] = src[ii];
		i++;
	}
	if (ii < n)
	{
		jj = ii;
		while (jj < n)
		{
			dest[jj] = '\0';
			jj++;
		}
	}
	return (s);
}

/**
 **_strncat - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int ii, jj;
	char *s = dest;

	ii = 0;
	jj = 0;
	while (dest[ii] != '\0')
		ii++;
	while (src[jj] != '\0' && jj < n)
	{
		dest[ii] = src[jj];
		ii++;
		jj++;
	}
	if (jj < n)
		dest[ii] = '\0';
	return (s);
}

/**
 **_strchr - locates a character in a string
 *@s: the string to be parsed
 *@c: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
