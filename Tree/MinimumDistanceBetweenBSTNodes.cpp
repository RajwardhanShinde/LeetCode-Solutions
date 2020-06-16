void inorder(TreeNode *root, vector<int> &trav) {
    if(root == NULL)
        return;
    inorder(root->left, trav);
    trav.push_back(root->val);
    inorder(root->right, trav);
}
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        vector<int> trav;
        inorder(root, trav);
        int minDiff = INT_MAX;
        for(int i = 1; i < trav.size(); i++) 
            minDiff = min(minDiff, (abs(trav[i-1] - trav[i])));
        return minDiff;
    }
};
