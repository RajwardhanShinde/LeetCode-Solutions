class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int max_size = amount + 1;
        vector<int> dp(max_size + 1, max_size);
        dp[0] = 0;
        int n = coins.size();
        for (int n = 1; n <= amount; n++) {
            for (int i = 0; i < coins.size(); i++) {
                if (n - coins[i] >= 0) {
                    int subprob = dp[n - coins[i]];
                    dp[n] = min(dp[n], subprob + 1);
                }
            }
        }
        return dp[amount] > amount ? - 1 : dp[amount];
    }
};