TreeNode* newNode(TreeNode *node, TreeNode *tree1, TreeNode *tree2) {
    if(tree1 && tree2)
        node = new TreeNode(tree1->val + tree2->val);
    else if(tree1 == NULL && tree2 != NULL)
        node = new TreeNode(tree2->val);
    else if(tree1 != NULL && tree2 == NULL)
        node = new TreeNode(tree1->val);
    return node;
}

TreeNode* merge(TreeNode *tree1, TreeNode *tree2, TreeNode *newroot) {
    if(tree1 == NULL)
        return tree2;
    if(tree2 == NULL)
        return tree1;
    newroot->left = merge(tree1->left, tree2->left, newNode(newroot->left, tree1->left, tree2->left));
    newroot->right = merge(tree1->right, tree2->right, newNode(newroot->right, tree1->right, tree2->right));
    return newroot;
}

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode *newroot = NULL;
        if(t1 == NULL && t2 == NULL)
            return NULL;
        if(t1 == NULL)
            newroot = new TreeNode(t2->val);
        else if(t2 == NULL)
            newroot = new TreeNode(t1->val);
        else
            newroot = new TreeNode(t1->val + t2->val);
        newroot = merge(t1, t2, newroot);
        return newroot;
    }
};
