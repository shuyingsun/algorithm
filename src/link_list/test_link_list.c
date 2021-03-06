#include "../../lib/link_list/static_link_list_lib.h"

int main(int argc, char *argv[]) {
    int val;
    int op;
    link_list *my_link_list = NULL;

    my_link_list = create_link_list();
    if (my_link_list == NULL)
        return 0;

    do {
        printf("(Insert(input 1) / Delete(input 2) / Quit(intput 3): ");
        scanf("%d", &op);
        if (op == 1) {
            printf("Input an integer to insert: ");
            scanf("%d", &val);
            link_list_insert(my_link_list, val);
        } else if (op == 2) {
            printf("Input an integer to delete: ");
            scanf("%d", &val);
            link_list_delete(my_link_list, val);
        } else {
            op = 0;
        }
        print_link_list(my_link_list);
    } while (op != 0);

    destroy_link_list(my_link_list);
    return 0;
}
