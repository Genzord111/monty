#include <stdio.h>
#include "monty.h"

/**
 * main - mainfunction for processing file with monty codes
 * Return: returns 0 or 1 if successfull or failed
 */

int main(int argc, char *argv[])
{
	FILE *fileptr;
        char fileContent[200];

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		return (1);
	}

	fileptr = fopen(argv[1], "r");
	if (fileptr == NULL)
	{
		printf("Error: Can't open file <%s>\n", argv[1]);
		return (1);
	}

	while(fgets(fileContent, 200, fileptr))
	{
		printf("%s", fileContent);
	}

	fclose(fileptr);

	return (0);
}
