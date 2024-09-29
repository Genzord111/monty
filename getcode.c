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

int getcode(char *line, unsigned int line_number, instruction_t *instructions, stack_t **stack)
{
    parse_line(line, line_number, instructions, stack);
    return 0;
}

