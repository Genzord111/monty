#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include<stdlib.h>
#include "monty.h"

/**
 * parse_line - breaks string into opcodes
 * @n: line number
 * @instructions: pointer to instructions structure
 * @line: string from each line of file
 * @h: head pointer to stack
 * Return: integer 0 for success
 */

void parse_line(char *line, unsigned int n, instruction_t *instructions, stack_t **h)
{
    char *opcode;
    char *arg;
    char *endptr;
    long value;

    /* Split line to opcode and argument */
    opcode = strtok(line, " \t\n");
    /* Ignore blank lines or comments */

    if (opcode == NULL || opcode[0] == '#')
	    return;

    if (strcmp(opcode, "push") == 0)
    {
        arg = strtok(NULL, " \t\n");

        if (arg == NULL)
        {
            fprintf(stderr, "L%u: usage: push integer\n", n);
            exit(EXIT_FAILURE);
        }

	/* Convert argument to integer */
        value = strtol(arg, &endptr, 10);

	/* Check for non-integer values */
        if (*endptr != '\0')
        {
            fprintf(stderr, "L%u: usage: push integer\n", n);
            exit(EXIT_FAILURE);
        }

        execute(instructions, "push", h, (unsigned int)value);
    }
    else
    {
        execute(instructions, opcode, h, n);
    }
}
