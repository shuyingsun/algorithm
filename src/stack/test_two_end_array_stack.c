#include <stdio.h>
#include <stdbool.h>
#include "../../lib/stack/static_stack_lib.h"
#include "../../lib/array/static_array_lib.h"

int main(int argc, char *argv[]) {
    int ret = -1;
    int val;
    int stackSize;
    two_end_array_stack *my_stack;

    printf("Please input an integer larger than 0 to specify the size of stack: ");
    scanf("%d", &stackSize);
    if (stackSize <= 0) {
        printf("Invalid stack size!\n");
        return 0;
    }

    my_stack = create_two_end_array_stack(stackSize);
    if (my_stack == NULL)
        return 0;

    ret = push_two_end_array_stack(my_stack, 4, true);
    printf("After push(S, 4), stack.top1 = %d, stack.top2 = %d:", my_stack->top1, my_stack->top2);
    print_num_array(my_stack->nums, my_stack->stackSize);

    ret = push_two_end_array_stack(my_stack, 1, false);
    printf("After push(S, 1), stack.top = %d, stack.top2 = %d:", my_stack->top1, my_stack->top2);
    print_num_array(my_stack->nums, my_stack->stackSize);

    ret = push_two_end_array_stack(my_stack, 3, false);
    printf("After push(S, 3), stack.top = %d, stack.top2 = %d:", my_stack->top1, my_stack->top2);
    print_num_array(my_stack->nums, my_stack->stackSize);

    ret = pop_two_end_array_stack(my_stack, &val, true);
    printf("After pop(S), stack.top = %d, stack.top2 = %d:", my_stack->top1, my_stack->top2);
    print_num_array(my_stack->nums, my_stack->stackSize);

    ret = push_two_end_array_stack(my_stack, 8, false);
    printf("After push(S, 8), stack.top = %d, stack.top2 = %d:", my_stack->top1, my_stack->top2);
    print_num_array(my_stack->nums, my_stack->stackSize);

    ret = pop_two_end_array_stack(my_stack, &val, false);
    printf("After pop(S), stack.top = %d, stack.top2 = %d:", my_stack->top1, my_stack->top2);
    print_num_array(my_stack->nums, my_stack->stackSize);

    ret = pop_two_end_array_stack(my_stack, &val, true);
    // Expect to fail as empty stack
    printf("After pop(S), stack.top = %d, stack.top2 = %d:", my_stack->top1, my_stack->top2);
    print_num_array(my_stack->nums, my_stack->stackSize);

    destroy_two_end_array_stack(my_stack);
    return 0;
}
