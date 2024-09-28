#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * main - mainfunction for processing file with monty codes
 * @argc: indicates number of command line arguments
 * @argv: array containing command line arguments
 * Return: returns 0 or 1 if successfull or failed
 */

int main(int argc, char *argv[])
{
	stack_t *head = NULL;
	int isEmpty = 1;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	FILE *fileptr;
	char fileContent[200];

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fileptr = fopen(argv[1], "r");
	if (fileptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file <%s>\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(fileContent, sizeof(fileContent), fileptr))
	{
		isEmpty = 0;
		getcode(lineprocessor(fileContent), instructions, &head);
	}

	if (isEmpty == 1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	fclose(fileptr);

	return (0);
}
