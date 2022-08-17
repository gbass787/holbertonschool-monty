#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>
#include <stdarg.h>
#include <unistd.h>

/**
 *struct monty_s - main variables of monty
 *@file: monty file
 *@line: line
 *@quenue: flag to indicate if its stack or quenue mode
 *@stack_mount: stack builing
 *@line_count: line to be read from stack
 */
typedef struct monty_s
{
  bool quenue;
  char *line = NULL;
  FILE *file;
  size_t stack_mount;
}monty_t;

#define STACK 0
#define QUENUE 1

extern char *glovar;
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
        void (*f)(stack_t **stack, unsigned int line_count);
} instruction_t;

void push(stack_t **stack, unsigned int line_count);
void pall(stack_t **stack, __attribute__((unused))unsigned int line_count);
void executeop(char *opcode, stack_t **stack, unsigned int line_count);
void _pint(stack_t **stack, unsigned int line_count);
int getdigit(char *digit);
unsigned int count(stack_t *stack);
int main(int argc char *filename);
void _fdlist(stack_t *topstack)
void nop(stack_t **stack, unsigned int line_count)
#endif
