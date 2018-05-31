#include "../../lib/tree/static_tree_lib.h"

int main(int argc,char *argv[]) {
    cs_tree_node_t *root = NULL;

    root = create_cs_tree();
    if (root == NULL) {
        printf("root is NULL.\n");
        return 0;
    }

    printf("Child-Sibling Tree traversal:\n");
    traverse_cs_tree(root);
    printf("\n");

    destroy_cs_tree(&root);
    return 0;
}
