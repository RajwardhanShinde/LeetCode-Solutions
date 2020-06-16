class Solution {
public:
    
    vector<int> dfs(TreeNode *root, int target, int depth, int parent) {
        if(root == NULL) 
            return {};
        if(root->val == target)
            return {depth, parent};
        else {
            parent = root->val;
            vector<int> left = dfs(root->left, target, depth+1, parent);
            vector<int> right = dfs(root->right, target, depth+1, parent);
            
            if(left.empty())
                return right;
            else 
                return left;
        }
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        vector<int> d1 = dfs(root, x, 0, -1);
        vector<int> d2 = dfs(root, y, 0, -1);
        if(d1[0] == d2[0] && d1[1] != d2[1])
            return true;
        return false;
    }
};
