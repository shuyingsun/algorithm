#include <stdio.h>
#include "../../lib/stack/static_stack_lib.h"
#include "../../lib/array/static_array_lib.h"

int main(int argc, char *argv[]) {
    int ret = -1;
    int val;
    int stackSize;
    array_stack *my_stack;

    printf("Please input an integer larger than 0 to specify the size of stack: ");
    scanf("%d", &stackSize);
    if (stackSize <= 0) {
        printf("Invalid stack size!\n");
        return 0;
    }

    my_stack = create_array_stack(stackSize);
    if (my_stack == NULL)
        return 0;

    ret = push_array_stack(my_stack, 4);
    printf("After push(S, 4), stack.top = %d:", ret);
    print_num_array(my_stack->nums, my_stack->stackSize);

    ret = push_array_stack(my_stack, 1);
    printf("After push(S, 1), stack.top = %d:", ret);
    print_num_array(my_stack->nums, my_stack->stackSize);

    ret = push_array_stack(my_stack, 3);
    printf("After push(S, 3), stack.top = %d:", ret);
    print_num_array(my_stack->nums, my_stack->stackSize);

    ret = pop_array_stack(my_stack, &val);
    printf("After pop(S), stack.top = %d:", ret);
    print_num_array(my_stack->nums, my_stack->stackSize);

    ret = push_array_stack(my_stack, 8);
    printf("After push(S, 8), stack.top = %d:", ret);
    print_num_array(my_stack->nums, my_stack->stackSize);

    ret = pop_array_stack(my_stack, &val);
    printf("After pop(S), stack.top = %d:", ret);
    print_num_array(my_stack->nums, my_stack->stackSize);

    destroy_array_stack(my_stack);
    return 0;
}
