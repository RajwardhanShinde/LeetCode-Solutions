class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int frontProduct = 1, backProduct = 1;
        int ans = INT_MIN, n = nums.size();
        for (int i = 0; i < n; i++) {
            frontProduct *= nums[i];
            backProduct *= nums[n - i - 1];
            ans = max(max(frontProduct, backProduct), ans);
            frontProduct = frontProduct == 0 ? 1 : frontProduct;
            backProduct = backProduct == 0 ? 1 : backProduct;
        }
        return ans;
    }
};