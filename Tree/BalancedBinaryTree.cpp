class Solution {
public:
    int Depth(TreeNode *root) {
        if(!root) return 0;
        int L = Depth(root->left);
        int R = Depth(root->right);
        return 1 + max(L, R);
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        int left = Depth(root->left);
        int right = Depth(root->right);
        
        if(abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right))
            return true;
        return false;
    }
};
