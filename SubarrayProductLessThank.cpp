class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int prod = 1;
        int ans = 0, left = 0, right = 0;
        for(int i = 0; i < nums.size(); i++) {
            prod *= nums[i];
            while(prod >= k) {
                prod /= nums[left];
                left += 1;
            }
            ans += right - left + 1;
            right++;
        }
        return ans;
    }
};
