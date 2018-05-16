#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct array_stack_s {
    int *nums;
    int stackSize;
    int top;
} array_stack;

typedef struct two_end_array_stack_s {
    int *nums;
    int stackSize;
    int top1;
    int top2;
} two_end_array_stack;

typedef struct queue_by_two_stacks_s {
    array_stack *stack1;
    array_stack *stack2;
} queue_by_two_stacks;

array_stack* create_array_stack(int stackSize);
void destroy_array_stack(array_stack *stack);
bool is_array_stack_full(array_stack stack);
bool is_array_stack_empty(array_stack stack);
int push_array_stack(array_stack *stack, int val);
int pop_array_stack(array_stack *stack, int *val);

two_end_array_stack* create_two_end_array_stack(int stackSize);
void destroy_two_end_array_stack(two_end_array_stack *stack);
bool is_two_end_array_stack_full(two_end_array_stack stack);
bool is_two_end_array_stack_empty(two_end_array_stack stack, bool is_forward);
int push_two_end_array_stack(two_end_array_stack *stack, int val, bool is_forward);
int pop_two_end_array_stack(two_end_array_stack *stack, int *val, bool is_forward);

queue_by_two_stacks* create_queue_by_two_stacks(int queueSize);
void destroy_queue_by_two_stacks(queue_by_two_stacks *queue);
bool is_queue_by_two_stacks_full(queue_by_two_stacks queue);
bool is_queue_by_two_stacks_empty(queue_by_two_stacks queue);
void enqueue_by_two_stacks(queue_by_two_stacks *queue, int val);
bool dequeue_by_two_stacks(queue_by_two_stacks *queue, int *val);
