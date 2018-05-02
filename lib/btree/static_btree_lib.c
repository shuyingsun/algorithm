#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "static_btree_lib.h"

int create_tree(struct TreeNode **node) {
    int val = 0;

    printf("Input TreeNode value, enter \"0\" to indicate NULL.\n");
    scanf ("%d", &val);
    if (val == 0) {
        *node = NULL;
    } else {
        *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        if (*node == NULL) {
            printf ("Malloc failure.\n");
            return 0;
        }
        (*node)->val = val;
        (*node)->left = NULL;
        (*node)->right = NULL;
        create_tree(&((*node)->left));
        create_tree(&((*node)->right));
    }
    return 1;
}

void destroy_tree(struct TreeNode **node) {
    struct TreeNode *left, *right;

    if (*node == NULL)
        return;

    left = (*node)->left;
    right = (*node)->right;
    (*node)->left = NULL;
    (*node)->right = NULL;
    free(*node);
    *node = NULL;

    destroy_tree(&left);
    destroy_tree(&right);
}
