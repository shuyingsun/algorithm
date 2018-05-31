#include "../../lib/tree/static_tree_lib.h"

int main(int argc,char *argv[]) {
    tree_node_t *root = NULL;

    root = create_tree();
    if (root == NULL) {
        printf("root is NULL.\n");
        return 0;
    }

    printf("\n");
    printf("Recursion for pre-order traversal:\n");
    preorder_traversal_recur(root);
    printf("\n");

    printf("\n");
    printf("Pre-order traversal with stack usage:\n");
    preorder_traversal_stack(root);
    printf("\n");

    destroy_tree(&root);
    return 0;
}
