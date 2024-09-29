#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include<stdlib.h>
#include "monty.h"

/**
 * pint - prints the first element of the stack
 * @h: pointer to stack
 * @n: integer
 * Return: void
 */

void pint(stack_t **h, unsigned int n)
{
	stack_t *current = *h;

	if (current != NULL)
	{
		printf("%d\n", current->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty", n);
		exit(EXIT_FAILURE);
	}
}

