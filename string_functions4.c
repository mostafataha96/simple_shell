#include "shell.h"

/**
 * **strtow - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)
{
	int ii, jj, kk, mm, numwordss = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (ii = 0; str[ii] != '\0'; ii++)
		if (!is_delim(str[ii], d) && (is_delim(str[ii + 1], d) || !str[ii + 1]))
			numwordss++;

	if (numwordss == 0)
		return (NULL);
	s = malloc((1 + numwordss) * sizeof(char *));
	if (!s)
		return (NULL);
	for (ii = 0, jj = 0; jj < numwordss; jj++)
	{
		while (is_delim(str[ii], d))
			ii++;
		kk = 0;
		while (!is_delim(str[ii + kk], d) && str[ii + kk])
			kk++;
		s[jj] = malloc((kk + 1) * sizeof(char));
		if (!s[jj])
		{
			for (kk = 0; kk < jj; kk++)
				free(s[kk]);
			free(s);
			return (NULL);
		}
		for (mm = 0; mm < kk; mm++)
			s[jj][mm] = str[ii++];
		s[jj][mm] = 0;
	}
	s[jj] = NULL;
	return (s);
}

/**
 * **strtow2 - splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int ii, jj, kk, mm, numwordss = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (ii = 0; str[ii] != '\0'; ii++)
		if ((str[ii] != d && str[ii + 1] == d) ||
		    (str[ii] != d && !str[ii + 1]) || str[ii + 1] == d)
			numwordss++;
	if (numwordss == 0)
		return (NULL);
	s = malloc((1 + numwordss) * sizeof(char *));
	if (!s)
		return (NULL);
	for (ii = 0, jj = 0; jj < numwordss; jj++)
	{
		while (str[ii] == d && str[ii] != d)
			ii++;
		kk = 0;
		while (str[ii + kk] != d && str[ii + kk] && str[ii + kk] != d)
			kk++;
		s[jj] = malloc((kk + 1) * sizeof(char));
		if (!s[jj])
		{
			for (kk = 0; kk < jj; kk++)
				free(s[kk]);
			free(s);
			return (NULL);
		}
		for (mm = 0; mm < kk; mm++)
			s[jj][mm] = str[ii++];
		s[jj][mm] = 0;
	}
	s[jj] = NULL;
	return (s);
}
