#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "static_stack_lib.h"

/*
 * Create a new stack with specified stack size
 * If success, return stack size
 * If failure, return -1
 */
int create_array_stack(array_stack *new_stack) {
    unsigned int stackSize = 0;
    int *new_nums = NULL;

    printf("Please input an integer larger than 0 to specify the size of stack: ");
    scanf("%d", &stackSize);

    if (stackSize <= 0) {
        printf("Invalid stack size!\n");
        return -1;
    }

    new_nums = (int *)malloc(sizeof(int) * stackSize);
    if (new_nums == NULL) {
        printf("Malloc failure.\n");
        return -1;
    }

    new_stack->nums = new_nums;
    new_stack->stackSize = stackSize;
    new_stack->top = -1;
}

void destroy_array_stack(array_stack *stack) {
    if (stack->nums != NULL) {
        free(stack->nums);
        stack->nums = NULL;
    }
    stack->stackSize = 0;
    stack->top = -1;
}

/*
 * Check whether the stack is full
 * If full, return TRUE
 * Else, return FALSE
 */
bool is_array_stack_full(array_stack stack) {
    return (stack.top == stack.stackSize - 1);
}

/*
 * Check whether the stack is empty
 * If empty, return TRUE
 * Else, return FALSE
 */
bool is_array_stack_empty(array_stack stack) {
    return (stack.top == -1);
}

/*
 * Insert a new element with specified value into the stack
 * If success, return the updated top
 * If failure, return -1
 */
int push_array_stack(array_stack *stack, int val) {
    if (is_array_stack_full(*stack)) {
        printf("The stack is full, push failed.\n");
        return -1;
    }
    stack->top += 1;
    stack->nums[stack->top] = val;
    return stack->top;
}

/*
 * Delete top element from the stack, the value of top element would be saved in param @val
 * If success, return the updated top
 * If failure, return -1
 */
int pop_array_stack(array_stack *stack, int *val) {
    if (is_array_stack_empty(*stack)) {
        printf("The stack is empty, pop failed.\n");
        return -1;
    }
    *val = stack->nums[stack->top];
    stack->top -= 1;
    return stack->top;
}
