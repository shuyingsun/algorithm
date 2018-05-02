struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int create_tree(struct TreeNode **node);
void destroy_tree(struct TreeNode **node);
