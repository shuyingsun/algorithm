#include "../../lib/tree/static_tree_lib.h"

int main(int argc,char *argv[]) {
    struct TreeNode *root = NULL;
    int ret = 0;

    ret = create_tree(&root);
    if (ret == 0) {
        printf("Creating tree failed.\n");
        return 0;
    }
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
