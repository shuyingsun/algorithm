#include "../../lib/queue/static_queue_lib.h"

int main(int argc, char *argv[]) {
    int val;
    int op, ret;
    link_list_queue *my_queue = NULL;

    my_queue = create_link_list_queue();
    if (my_queue == NULL)
        return 0;

    do {
        printf("(Enqueue(input 1) / Dequeue(input 2) / Quit(intput 3): ");
        scanf("%d", &op);
        if (op == 1) {
            printf("Input an integer to enqueue: ");
            scanf("%d", &val);
            enqueue_link_list(my_queue, val);
        } else if (op == 2) {
            ret = dequeue_link_list(my_queue, &val);
            if (ret) {
                printf("Ret: %d, Dequeue val: %d.\n", ret, val);
            }
        } else {
            op = 0;
        }
    } while (op != 0);

    destroy_link_list_queue(my_queue);
    return 0;
}
