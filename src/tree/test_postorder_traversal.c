#include "../../lib/tree/static_tree_lib.h"

int postorder_traversal(struct TreeNode *root);
int seek_priv (struct TreeNode *curr, struct TreeNode **priv);
void reverse_print(struct TreeNode *curr, struct TreeNode *priv, int num);

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
    printf("Recursion for post-order traversal:\n");
    postorder_traversal_recur(root);
    printf("\n");
    printf("\n");

    printf("Non-recursion without stack use for post-order traversal:\n");
    ret = postorder_traversal(root);
    if (ret == 0) {
        printf("Non-recursion post-order traversal failed.\n");
        return 0;
    }
    printf("\n");

    destroy_tree(&root);
    return 0;
}

int postorder_traversal(struct TreeNode *root) {
    struct TreeNode *priv = NULL, *curr = NULL, *dummy = NULL;
    int num;

    dummy = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (dummy == NULL) {
        printf("Malloc failure.\n");
        return 0;
    }
    dummy->val = 0;
    dummy->left = root;

    curr = dummy;
    do {
        num = seek_priv(curr, &priv);
        //printf("Finished seek_priv, curr: %d, priv: %d, num: %d\n", curr->val, priv->val, num);

        if (num == 0) {
            /* curr->left is NULL */
            curr = curr->right;
            priv = NULL;
            //printf("In postorder_traversal, got num = 0 after seeking priv.\n");
        } else {
            if (priv->right == curr) {
                //printf("In postorder_traversal, priv->right is curr after seeking priv.\n");
                priv->right = NULL;
                reverse_print(curr, priv, num);
                //if (curr->right != NULL) {
                    curr = curr->right;
                //}
            } else {
                //printf("In postorder_traversal, priv->right is not curr after seeking priv.\n");
                priv->right = curr;
                curr = curr->left;
                //printf("In postorder_traversal, priv->right is not curr after seeking priv, curr moved to left.\n");
            }
        }
        //printf("Updated curr val: %d\n", curr->val);
    } while (curr != NULL);

    return 1;
}

int seek_priv (struct TreeNode *curr, struct TreeNode **priv) {
    int count = 0;

    if (curr == NULL) {
        printf("In seek_priv, curr is NULL.\n");
    }

    if (curr->left == NULL) {
        return 0;
    }

    *priv = curr->left;
    count++;

    while ((*priv)->right != NULL && (*priv)->right != curr) {
        (*priv) = (*priv)->right;
        count++;
    }
    //printf("In seek_priv end, curr val: %d, priv val: %d, count: %d\n", curr->val, (*priv)->val, count);
    return count;
}

void reverse_print(struct TreeNode *curr, struct TreeNode *priv, int num) {
    struct TreeNode *temp = curr->left;
    int idx = 0;
    int *node_val = (int *)malloc(sizeof(int) * num);

    if (node_val == NULL) {
        printf("Malloc failure.\n");
        return;
    }

    for (idx = num; idx > 0; idx--) {
        node_val[idx-1] = temp->val;
        temp = temp->right;
    }

    for (idx = 0; idx < num; idx++) {
        printf("%d ", node_val[idx]);
    }

    free(node_val);
}
