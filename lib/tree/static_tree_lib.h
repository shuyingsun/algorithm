#ifndef __STATIC_BTREE_LIB_H__
#define __STATIC_BTREE_LIB_H__

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
}tree_node_t;

int create_tree(struct TreeNode **node);
void destroy_tree(struct TreeNode **node);
void preorder_traversal_recur(struct TreeNode *root);
void preorder_traversal_stack(struct TreeNode *root);
void postorder_traversal_recur(struct TreeNode *root);




typedef struct stack_for_tree_s {
    tree_node_t **nodes;
    int stackSize;
    int top;
} stack_for_tree;

stack_for_tree* create_stack_for_tree(int stackSize);
void destroy_stack_for_tree(stack_for_tree *stack);
bool is_stack_for_tree_full(stack_for_tree stack);
bool is_stack_for_tree_empty(stack_for_tree stack);
int push_stack_for_tree(stack_for_tree *stack, tree_node_t *new_node);
int pop_stack_for_tree(stack_for_tree *stack, tree_node_t **node);

#endif /* __STATIC_BTREE_LIB_H__ */
