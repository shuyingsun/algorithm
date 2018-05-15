#include <stdbool.h>

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

array_stack* create_array_stack();
void destroy_array_stack(array_stack *stack);
bool is_array_stack_full(array_stack stack);
bool is_array_stack_empty(array_stack stack);
int push_array_stack(array_stack *stack, int val);
int pop_array_stack(array_stack *stack, int *val);

two_end_array_stack* create_two_end_array_stack();
void destroy_two_end_array_stack(two_end_array_stack *stack);
bool is_two_end_array_stack_full(two_end_array_stack stack);
bool is_two_end_array_stack_empty(two_end_array_stack stack, bool is_forward);
int push_two_end_array_stack(two_end_array_stack *stack, int val, bool is_forward);
int pop_two_end_array_stack(two_end_array_stack *stack, int *val, bool is_forward);
