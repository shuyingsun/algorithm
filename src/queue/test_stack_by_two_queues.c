#include "../../lib/queue/static_queue_lib.h"
#include "../../lib/array/static_array_lib.h"

int main(int argc, char *argv[]) {
    int stackSize;
    int op;
    int val;
    stack_by_two_queues *my_stack = NULL;

    printf("Please input an integer larger than 0 to specify the size of stack: ");
    scanf("%d", &stackSize);
    if (stackSize <= 0) {
        printf("Invalid stack size!\n");
        return 0;
    }

    my_stack = create_stack_by_two_queues(stackSize);
    if (my_stack == NULL)
        return 0;

    do {
        printf("Push(input 1) / Pop(input 2) / Quit(intput 3): ");
        scanf("%d", &op);
        if (op == 1) {
            printf("Input an integer to push: ");
            scanf("%d", &val);
            push_by_two_queues(my_stack, val);
        } else if (op == 2) {
            if (pop_by_two_queues(my_stack, &val))
                printf("The value of pop-ed element is %d.\n", val);
        } else {
            op = 0;
        }
    } while (op != 0);

    destroy_stack_by_two_queues(my_stack);
    return 0;
}

