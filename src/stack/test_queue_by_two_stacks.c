#include "../../lib/stack/static_stack_lib.h"
#include "../../lib/array/static_array_lib.h"

int main(int argc, char *argv[]) {
    int op = 0;
    int val;
    int queueSize;
    queue_by_two_stacks *my_queue = NULL;

    printf("Please input an integer larger than 0 to specify the size of queue: ");
    scanf("%d", &queueSize);
    if (queueSize <= 0) {
        printf("Invalid queue size!\n");
        return 0;
    }

    my_queue = create_queue_by_two_stacks(queueSize);
    if (my_queue == NULL)
        return 0;

    do {
        printf("Enqueue(input 1) / Dequeue(input 2) / Quit(intput 3): ");
        scanf("%d", &op);
        if (op == 1) {
            printf("Input an integer to enqueue: ");
            scanf("%d", &val);
            enqueue_by_two_stacks(my_queue, val);
        } else if (op == 2) {
            if (dequeue_by_two_stacks(my_queue, &val))
            //if (ret == 1)
                printf("The value of dequeue-ed element is %d.\n", val);
        } else {
            op = 0;
        }
    } while(op != 0);

    destroy_queue_by_two_stacks(my_queue);
    return 0;
}
