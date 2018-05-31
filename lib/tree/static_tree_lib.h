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

tree_node_t* create_tree();
void destroy_tree(tree_node_t **node);
void preorder_traversal_recur(tree_node_t *root);
void preorder_traversal_stack(tree_node_t *root);
void postorder_traversal_recur(tree_node_t *root);



typedef struct CSTreeNode {
    int val;
    struct CSTreeNode *left;
    struct CSTreeNode *sibling;
} cs_tree_node_t;

cs_tree_node_t* create_cs_tree();
void destroy_cs_tree(cs_tree_node_t **node);
void traverse_cs_tree(cs_tree_node_t *root);



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
