class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL)
            return NULL;
        if(root->val == val) 
            return root;
        TreeNode* left = root->left ? searchBST(root->left, val) : NULL;
        TreeNode *right = root->right ? searchBST(root->right, val) : NULL;
        if(left == NULL)
            return right;
        if(right == NULL)
            return left;
        return root;
    }
};
