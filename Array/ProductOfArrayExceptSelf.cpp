class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pref_mul = 1, n = nums.size(), suf_mul = 1;
        vector<int> pref;
        for(int i = 0; i < n; i++) {
            pref.push_back(pref_mul);
            pref_mul *= nums[i];
        }
        for(int i = n-1; i >= 0; i--) {
            pref[i] *= suf_mul;
            suf_mul *= nums[i];
        }
        return pref;
    }
};
