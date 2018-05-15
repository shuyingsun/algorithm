#include <stdbool.h>

typedef struct array_stack_s {
    int *nums;
    int stackSize;
    int top;
} array_stack;

int create_array_stack(array_stack *new_stack);
void destroy_array_stack(array_stack *stack);
bool is_array_stack_full(array_stack stack);
bool is_array_stack_empty(array_stack stack);
int push_array_stack(array_stack *stack, int val);
int pop_array_stack(array_stack *stack, int *val);
