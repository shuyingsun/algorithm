#include "static_tree_lib.h"

tree_node_t* create_tree() {
    tree_node_t *node, *left, *right;
    int val = 0;

    printf("Input TreeNode value, enter \"0\" to indicate NULL.\n");
    scanf("%d", &val);
    if (val == 0) {
        node = NULL;
    } else {
        node = (tree_node_t*)malloc(sizeof(tree_node_t));
        if (node == NULL) {
            printf("Malloc failure.\n");
            return NULL;
        }
        node->val = val;
        left = create_tree();
        node->left = left;
        right = create_tree();
        node->right = right;
    }
    return node;
}

cs_tree_node_t* create_cs_tree() {
    cs_tree_node_t *node, *left, *sibling;
    int val = 0;

    printf("Input TreeNode value, enter \"0\" to indicate NULL.\n");
    scanf("%d", &val);
    if (val == 0) {
        node = NULL;
    } else {
        node = (cs_tree_node_t*)malloc(sizeof(cs_tree_node_t));
        if (node == NULL) {
            printf("Malloc failure.\n");
            return NULL;
        }
        node->val = val;
        left = create_cs_tree();
        node->left = left;
        sibling = create_cs_tree();
        node->sibling = sibling;
    }
    return node;
}


void destroy_tree(tree_node_t **node) {
    tree_node_t *left, *right;

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
    free(*node);
}

void destroy_cs_tree(cs_tree_node_t **node) {
    cs_tree_node_t *left, *sibling;

    if (*node == NULL)
        return;

    printf("Destroying node %d\n", (*node)->val);
    left = (*node)->left;
    sibling = (*node)->sibling;
    (*node)->left = NULL;
    (*node)->sibling = NULL;
    free(*node);
    *node = NULL;

    destroy_cs_tree(&left);
    destroy_cs_tree(&sibling);
    free(*node);
}

void preorder_traversal_recur(tree_node_t *root) {
    if (root == NULL)
        return;
    printf("%d ", root->val);
    preorder_traversal_recur(root->left);
    preorder_traversal_recur(root->right);
}

#define STACK_SIZE 30
void preorder_traversal_stack(tree_node_t *root) {
    stack_for_tree *stack = NULL;
    tree_node_t *curr = NULL;
    int ret = -1;

    if (root == NULL)
        return;

    stack = create_stack_for_tree(STACK_SIZE);
    if (stack == NULL) {
        printf("Create stack failed.\n");
        return;
    }

    curr = root;
    while (curr != NULL) {
        printf("%d ", curr->val);
        if (curr->right != NULL) {
            // printf("Push %d into the stack.\n", curr->right->val);
            ret = push_stack_for_tree(stack, curr->right);
            if (ret == -1)
                break;
        }
        if (curr->left != NULL) {
            // printf("Push %d into the stack.\n", curr->left->val);
            ret = push_stack_for_tree(stack, curr->left);
            if (ret == -1)
                break;
        }
        ret = pop_stack_for_tree(stack, &curr);
        if (ret < -1)
            break;
    }
    destroy_stack_for_tree(stack);
}

void traverse_cs_tree(cs_tree_node_t *root) {
    if (root == NULL)
        return;
    printf("%d ", root->val);
    traverse_cs_tree(root->sibling);
    traverse_cs_tree(root->left);
}

void postorder_traversal_recur(tree_node_t *root) {
    if (root == NULL)
        return;
    postorder_traversal_recur(root->left);
    postorder_traversal_recur(root->right);
    printf("%d ", root->val);
}







/*
 * Create a new stack with specified stack size
 * If success, return stack size
 * If failure, return -1
 */
stack_for_tree* create_stack_for_tree(int stackSize) {
    stack_for_tree* new_stack = NULL;
    tree_node_t **new_nodes = NULL;

    new_stack = (stack_for_tree *)malloc(sizeof(stack_for_tree));
    if (new_stack == NULL) {
        printf("Malloc failure for new_stack.\n");
        return NULL;
    }

    new_nodes = (tree_node_t **)malloc(sizeof(tree_node_t *) * stackSize);
    if (new_nodes == NULL) {
        printf("Malloc failure for new_nodes.\n");
        free(new_stack);
        return NULL;
    }

    new_stack->nodes = new_nodes;
    new_stack->stackSize = stackSize;
    new_stack->top = -1;

    return new_stack;
}

void destroy_stack_for_tree(stack_for_tree *stack) {
    if (stack == NULL)
        return;
    if (stack->nodes != NULL)
        free(stack->nodes);
    free(stack);
}

/*
 * Check whether the stack is full
 * If full, return TRUE
 * Else, return FALSE
 */
bool is_stack_for_tree_full(stack_for_tree stack) {
    return (stack.top == stack.stackSize - 1);
}

/*
 * Check whether the stack is empty
 * If empty, return TRUE
 * Else, return FALSE
 */
bool is_stack_for_tree_empty(stack_for_tree stack) {
    return (stack.top == -1);
}

/*
 * Insert a new element with specified value into the stack
 * If success, return the updated top
 * If failure, return -1
 */
int push_stack_for_tree(stack_for_tree *stack, tree_node_t *new_node) {
    if (is_stack_for_tree_full(*stack)) {
        printf("The stack is full, push failed.\n");
        return -1;
    }
    stack->top++;
    stack->nodes[stack->top] = new_node;
    return stack->top;
}

/*
 * Delete top element from the stack, the value of top element would be saved in param @val
 * If success, return the updated top
 * If failure, return -2
 */
int pop_stack_for_tree(stack_for_tree *stack, tree_node_t **node) {
    if (is_stack_for_tree_empty(*stack)) {
        printf("The stack is empty, pop failed.\n");
        return -2;
    }
    *node = stack->nodes[stack->top];
    stack->top -= 1;
    return stack->top;
}
