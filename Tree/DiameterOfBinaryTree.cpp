int height(TreeNode *root, int& ans) {
	if(root == NULL)
		return 0;
	int left = height(root->left, ans);
	int right = height(root->right, ans);
	ans = max(ans, 1+left+right);
	return 1 + max(left, right);
}
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
    if(root == NULL)
		return 0;
	int ans = INT8_MIN;
	int height_tree = height(root, ans);
	return ans-1;
    }
};
