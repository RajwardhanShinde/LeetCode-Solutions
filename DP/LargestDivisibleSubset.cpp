class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size() == 0)
            return vector<int>();
        
        if(nums.size() == 1) {
            vector<int>res;
            res.push_back(nums[0]);
            return res;
        }
        
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size()), parent(nums.size(), -1);
        int largest = 0, largestIndex = 0;
        dp[0] = 1;
        for(int i = 1; i < dp.size(); i++) {
            dp[i] = 1;
            for(int j = i - 1; j >= 0; j--) {
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if(dp[i] > largest) {
                largest = dp[i];
                largestIndex = i;
            } 
        }
        vector<int> res;
        for(int i = 0; i < largest; i++) {
            res.insert(res.begin(), nums[largestIndex]);
            largestIndex = parent[largestIndex];
        }
        return res;
    }
};
