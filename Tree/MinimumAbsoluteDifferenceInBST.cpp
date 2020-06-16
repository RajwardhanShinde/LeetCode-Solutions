void traverse(TreeNode *root, vector<int> &preorder) {
    if(root == NULL)
        return;
    preorder.push_back(root->val);
    if(root->left)
        traverse(root->left, preorder);
    if(root->right)
        traverse(root->right, preorder);
    return;
}

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> preorder;
        traverse(root, preorder);
        sort(preorder.begin(), preorder.end());
        int minDist = INT_MAX;
        for(int i = 0; i < preorder.size() - 1; i++) {
            minDist = min(minDist, (preorder[i+1] - preorder[i]));
        }
        return minDist;
    }
};
