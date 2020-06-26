class Solution {
public:
    void sumNumbers(TreeNode *root, int currSum, int& sum) {
        currSum = currSum * 10 + root->val;
        if(!root->left && !root->right)
            sum += currSum;
        if(root->left)
            sumNumbers(root->left, currSum, sum);
        if(root->right)
            sumNumbers(root->right, currSum, sum);
    }
    
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        int sum = 0;
        sumNumbers(root, 0, sum);
        return sum;
    }
};
