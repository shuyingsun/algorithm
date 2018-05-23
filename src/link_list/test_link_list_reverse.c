#include "../../lib/link_list/static_link_list_lib.h"

int main(int argc, char *argv[]) {
    int val;
    int op;
    link_list *my_link_list = create_link_list();

    if (my_link_list == NULL)
        return 0;

    do {
        printf("(Insert(input 1) / Quit(intput 2): ");
        scanf("%d", &op);
        if (op == 1) {
            printf("Input an integer to insert: ");
            scanf("%d", &val);
            link_list_insert(my_link_list, val);
        } else {
            op = 0;
        }
    } while (op != 0);

    printf("Before reverse: ");
    print_link_list(my_link_list);

    link_list_reverse(my_link_list);
    printf("After reverse: ");
    print_link_list(my_link_list);

    destroy_link_list(my_link_list);
    return 0;
}
