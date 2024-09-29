#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include<stdlib.h>
#include "monty.h"
#include <stdio.h>

/**
 * pall - prints all element in stack
 * @h: pointer to stack
 * @n: integer
 * Return: size of stack
 */

void pall(stack_t **h, unsigned int n)
{
	stack_t *current = *h;

	(void)n;

	while (current != NULL)
	{
		printf("%d\n", (current)->n);
		current = (current)->next;
	}
}
