#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "static_stack_lib.h"

/*
 * Create a new stack with specified stack size
 * If success, return stack size
 * If failure, return -1
 */
array_stack* create_array_stack() {
    unsigned int stackSize = 0;
    array_stack* new_stack = NULL;
    int *new_nums = NULL;

    printf("Please input an integer larger than 0 to specify the size of stack: ");
    scanf("%d", &stackSize);

    if (stackSize <= 0) {
        printf("Invalid stack size!\n");
        return NULL;
    }

    new_stack = (array_stack *)malloc(sizeof(array_stack));
    if (new_stack == NULL) {
        printf("Malloc failure for new_stack.\n");
        return NULL;
    }

    new_nums = (int *)malloc(sizeof(int) * stackSize);
    if (new_nums == NULL) {
        printf("Malloc failure for new_nums.\n");
        free(new_stack);
        return NULL;
    }

    new_stack->nums = new_nums;
    new_stack->stackSize = stackSize;
    new_stack->top = -1;

    return new_stack;
}

two_end_array_stack* create_two_end_array_stack() {
    unsigned int stackSize = 0;
    two_end_array_stack* new_stack = NULL;
    int *new_nums = NULL;

    printf("Please input an integer larger than 0 to specify the size of stack: ");
    scanf("%d", &stackSize);

    if (stackSize <= 0) {
        printf("Invalid stack size!\n");
        return NULL;
    }

    new_stack = (two_end_array_stack *)malloc(sizeof(two_end_array_stack));
    if (new_stack == NULL) {
        printf("Malloc failure for new_stack.\n");
        return NULL;
    }

    new_nums = (int *)malloc(sizeof(int) * stackSize);
    if (new_nums == NULL) {
        printf("Malloc failure for new_nums.\n");
        free(new_stack);
        return NULL;
    }

    new_stack->nums = new_nums;
    new_stack->stackSize = stackSize;
    new_stack->top1 = -1;
    new_stack->top2 = stackSize;

    return new_stack;
}

void destroy_array_stack(array_stack *stack) {
    if (stack == NULL)
        return;
    if (stack->nums != NULL)
        free(stack->nums);
    free(stack);
}

void destroy_two_end_array_stack(two_end_array_stack *stack) {
    if (stack == NULL)
        return;
    if (stack->nums != NULL)
        free(stack->nums);
    free(stack);
}

/*
 * Check whether the stack is full
 * If full, return TRUE
 * Else, return FALSE
 */
bool is_array_stack_full(array_stack stack) {
    return (stack.top == stack.stackSize - 1);
}

bool is_two_end_array_stack_full(two_end_array_stack stack) {
    return (stack.top1 == stack.top2 - 1);
}

/*
 * Check whether the stack is empty
 * If empty, return TRUE
 * Else, return FALSE
 */
bool is_array_stack_empty(array_stack stack) {
    return (stack.top == -1);
}

bool is_two_end_array_stack_empty(two_end_array_stack stack, bool is_forward) {
    if (is_forward)
        return stack.top1 == -1;
    return stack.top2 == stack.stackSize;
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
    stack->top++;
    stack->nums[stack->top] = val;
    return stack->top;
}

int push_two_end_array_stack(two_end_array_stack *stack, int val, bool is_forward) {
    if (is_two_end_array_stack_full(*stack)) {
        printf("The stack is full, push failed.\n");
        return -1;
    }
    if (is_forward) {
        stack->top1++;
        stack->nums[stack->top1] = val;
        return stack->top1;
    }
    stack->top2--;
    stack->nums[stack->top2] = val;
    return stack->top2;
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

int pop_two_end_array_stack(two_end_array_stack *stack, int *val, bool is_forward) {
    if (is_two_end_array_stack_empty(*stack, is_forward)) {
        printf("The stack is empty, pop failed.\n");
        return -1;
    }
    if (is_forward) {
        *val = stack->nums[stack->top1];
        stack->top1--;
        return stack->top1;
    }
    *val = stack->nums[stack->top2];
    stack->top2++;
    return stack->top2;
}
