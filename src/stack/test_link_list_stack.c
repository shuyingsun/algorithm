#include "../../lib/stack/static_stack_lib.h"

int main(int argc, char *argv[]) {
    int val;
    int op, ret;
    link_list_stack *my_stack = NULL;

    my_stack = create_link_list_stack();
    if (my_stack == NULL)
        return 0;

    do {
        printf("(Push(input 1) / Pop(input 2) / Quit(intput 3): ");
        scanf("%d", &op);
        if (op == 1) {
            printf("Input an integer to insert: ");
            scanf("%d", &val);
            push_link_list_stack(my_stack, val);
        } else if (op == 2) {
            ret = pop_link_list_stack(my_stack, &val);
            if (ret == 1) {
                printf("ret val: %d, pop val: %d.\n", ret, val);
            }
        } else {
            op = 0;
        }
    } while (op != 0);

    destroy_link_list_stack(my_stack);
    return 0;
}
