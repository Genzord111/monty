#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include<stdlib.h>
#include "monty.h"

/**
 * getcode - grabs
 * @instructions: pointer to instructions structure
 * @line: string from each line of file
 * @h: head pointer to stack
 * Return: integer 0 for success
 */

int getcode(char *line, instruction_t *instructions, stack_t **h)
{
	char *command[4] = {"push", "pall", "pop", "pint"};
	size_t len;
	size_t arr_size = (sizeof(command)) / (sizeof(command[0]));
	bool isequal = false;
	unsigned int value = 0;

	size_t i = 0;
	size_t j = 0;
	size_t k = 0;

	for (k = 0; k < arr_size; k++)
	{
		len = strlen(command[k]);
		for (i = 0; i < len; i++)
		{
			if (line[i] == command[k][i])
			{
				j = j + 1;
			}
		}
		if (j == strlen(command[k]))
		{
			isequal = true;
			break;
		}
		else
		{
			j = 0;
		}
	}

	if (isequal)
	{
		if (strcmp(command[k], "push") == 0)
		{
			char *arg_str = &line[len];
			char *endptr;

			value = (unsigned int)strtol(arg_str, &endptr, 10);

			if (*endptr != '\0' && !isspace(*endptr))
			{
				fprintf(stderr, "Invalid push argument\n");
				exit(EXIT_FAILURE);
			}
		}

		execute(instructions, command[k], h, value);
	}

	return (0);
}
