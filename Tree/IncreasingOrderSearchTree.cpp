class Solution {
public:
    TreeNode *incOrder(TreeNode *root, TreeNode *tail) {
        if(!root) return tail;
        TreeNode *res = incOrder(root->left, root);
        root->left = NULL;
        root->right = incOrder(root->right, tail);
        return res;
    }
    TreeNode* increasingBST(TreeNode* root){
        return incOrder(root, NULL);
    }
};
