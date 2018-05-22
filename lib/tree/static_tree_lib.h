#ifndef __STATIC_BTREE_LIB_H__
#define __STATIC_BTREE_LIB_H__

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int create_tree(struct TreeNode **node);
void destroy_tree(struct TreeNode **node);

#endif /* __STATIC_BTREE_LIB_H__ */
