/*
 * A simple implementation of Dynamically allocated Stacks.
 * The stack may be initialized only once and the size will remain
 * constant after that.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define 	MAX_STACK_SIZE									((uint32_t)127)

/***************************************************************************/
/* Stack operations														   */
/***************************************************************************/
STACK 	* 	stack_init(int32_t );
void 		stack_destroy(STACK *);
int32_t 	stack_push(STACK *, void *);
void 	* 	stack_pop(STACK *);

#define 	STACK_INIT(stack)					stack_init(stack)
#define 	STACK_DESTROY(stack)				stack_destroy(stack)
#define 	STACK_PUSH(stack, element)			stack_push(stack, (void *)&(element))
#define 	STACK_POP(stack)					stack_pop(stack)

#define PUSH_ALLOWED(stack)												\
	((((STACK *)stack)->top < (((STACK *)stack->size)-1))? TRUE: FALSE)

#define POP_ALLOWED(stack)												\
	((((STACK *)stack)->top > -1)? TRUE: FALSE)



/***************************************************************************/
/* Stack functions														   */
/***************************************************************************/
/***************************************************************************/
/* Name:	stack_init 												   	   */
/* Parameters: Input - 	size: Size of stack								   */
/*																		   */
/* Return:	STACK *: Pointer to allocated stack. Else NULL			   	   */
/* Purpose: Initializes a stack with given size							   */
/***************************************************************************/
STACK * stack_init(int32_t size)
{
	/***************************************************************************/
	/* Variable Declarations												   */
	/***************************************************************************/
	STACK *stack = NULL;
	int32_t i = 0;

	/***************************************************************************/
	/* Sanity Checks														   */
	/***************************************************************************/
	assert(size > 0);
	/***************************************************************************/
	/* Main Routine															   */
	/***************************************************************************/
	printf("Initialize stack of size %d", size);
	/***************************************************************************/
	/* Allocate a contiguous memory chunk of size 							   */
	/***************************************************************************/
	stack = (STACK *)malloc(sizeof(STACK)+ ((sizeof(void *))*size));
	if(stack == NULL)
	{
		printf("Error allocating stack");
		stack = NULL;
		goto EXIT_LABEL;
	}
	/***************************************************************************/
	/* Got memory															   */
	/***************************************************************************/
	printf("Got memory. Set defaults");
	stack->self = stack;
	stack->size = size;
	stack->top = -1;
	stack->stack = (void *)((char *)(stack)+ (uint32_t)sizeof(STACK));

	printf("Memory starts at: %p", stack->self);
	printf(("Stack starts at: %p", stack->stack);
	/***************************************************************************/
	/* Set all elements in stack to NULL									   */
	/***************************************************************************/
	for(i = 0 ; i< size; i++)
	{
		stack->stack[i] = NULL;
	}

EXIT_LABEL:
	/***************************************************************************/
	/* Exit Level Checks													   */
	/***************************************************************************/
	return stack;
}/* stack_init */

/***************************************************************************/
/* Name:	stack_destroy 											  	   */
/* Parameters: Input - 													   */
/*			   Input/Output -											   */
/* Return:	void														   */
/* Purpose: Deallocate memory for the stack								   */
/***************************************************************************/
void stack_destroy(STACK *stack)
{
	/***************************************************************************/
	/* Variable Declarations												   */
	/***************************************************************************/

	/***************************************************************************/
	/* Sanity Checks														   */
	/***************************************************************************/
	assert(stack != NULL);
	/***************************************************************************/
	/* Main Routine															   */
	/***************************************************************************/
	/* Since the chunk was fixed, we need not do anything else other than free */
	free(stack);
	/***************************************************************************/
	/* Exit Level Checks													   */
	/***************************************************************************/
	return;
}/* stack_destroy */

/***************************************************************************/
/* Name:	stack_push 												 	   */
/* Parameters: Input - 													   */
/*			   Input/Output -											   */
/* Return:	int32_t														   */
/* Purpose: Push the element to the stack								   */
/***************************************************************************/
int32_t stack_push(STACK *stack_ptr, void *value)
{
	/***************************************************************************/
	/* Variable Declarations												   */
	/***************************************************************************/
	int32_t ret_val = OK;
	/***************************************************************************/
	/* Sanity Checks														   */
	/***************************************************************************/
	assert(stack_ptr != NULL);
	assert(value != NULL);
	/***************************************************************************/
	/* Main Routine															   */
	/***************************************************************************/
	if(stack_ptr->top == (stack_ptr->size-1))
	{
		printf("Stack full. Push not allowed");
		ret_val = ERR;
		goto EXIT_LABEL;
	}
	stack_ptr->top +=1;
	stack_ptr->stack[stack_ptr->top] = value;

EXIT_LABEL:
	/***************************************************************************/
	/* Exit Level Checks													   */
	/***************************************************************************/
	return ret_val;
}/* stack_push */

/***************************************************************************/
/* Name:	stack_pop 												   */
/* Parameters: Input - 													   */
/*			   Input/Output -											   */
/* Return:	void *														   */
/* Purpose: Pops an element from the stack								   */
/***************************************************************************/
void * stack_pop(STACK *stack)
{
	/***************************************************************************/
	/* Variable Declarations												   */
	/***************************************************************************/
	void * element = NULL;
	/***************************************************************************/
	/* Sanity Checks														   */
	/***************************************************************************/
	assert(stack != NULL);
	/***************************************************************************/
	/* Main Routine															   */
	/***************************************************************************/
	if(stack->top < 0)
	{
		printf("Stack is empty. Pop not allowed");
		goto EXIT_LABEL;
	}

	element = stack->stack[stack->top];
	assert(element != NULL); /* MUST NOT BE NULL */

	stack->top -=1;

EXIT_LABEL:
	/***************************************************************************/
	/* Exit Level Checks													   */
	/***************************************************************************/
	return element;
}/* stack_pop */
