#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include<stdlib.h>
#include "monty.h"

/**
 * lineprocessor - processes each line of .m file
 * @line: pointer to each line
 * Return: processed string
 */

char *lineprocessor(char *line)
{
	size_t len = strlen(line);
	size_t i;
	size_t j = 0;
	char *pstr = malloc((len + 1) * sizeof(char));

	if (pstr == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		return (NULL);
	}

	for (i = 0; i <= len; i++)
	{
		if (islower(line[i]) || isdigit(line[i]))
		{
			pstr[j++] = line[i];
		}
	}

	pstr[j] = '\0';
	return (pstr);
}
