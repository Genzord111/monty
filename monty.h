#ifndef MONTY_H
#define MONTY_H

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void pint(stack_t **h, unsigned int n);
void pall(stack_t **h, unsigned int n);
void execute(instruction_t *instructions, char *opcode, stack_t **stack, unsigned int n);
char* lineprocessor(char *line);
void push(stack_t **head, unsigned int n);
int getcode(char *line, unsigned int line_number, instruction_t *instructions, stack_t **stack);
void parse_line(char *line, unsigned int line_number, instruction_t *instructions, stack_t **h);
#endif
