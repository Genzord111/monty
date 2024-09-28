#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include<stdlib.h>
#include "monty.h"

/**
 * execute - executes the instruction equivalent to the opcode
 * @instructions: pointer to instructions structure
 * @opcode: string from each line of file
 * @stack: head pointer to stack
 * @n: value to be added to stack
 * Return: void
 */

void execute(instruction_t *instructions, char *opcode, stack_t **stack, unsigned int n)
{
	int i;

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
		{
			((void (*)(stack_t **, unsigned int))instructions[i].f)(stack, n);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", n, opcode);
	exit(EXIT_FAILURE);
}
