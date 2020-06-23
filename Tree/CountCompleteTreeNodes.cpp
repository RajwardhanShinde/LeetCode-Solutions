class Solution {
public:
    void preorder(TreeNode *root, int& count) {
        if(!root)
            return;
        count++;
        preorder(root->left, count);
        preorder(root->right, count);
    } 
    
    
    int countNodes(TreeNode* root) {
        int count = 0;
        preorder(root, count);
        return count;
    }
};
