class Solution {
public:
    int change(int amount, vector<int>& coins) {   
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int dp[coins.size() + 1][amount + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int j = 1; j <= coins.size(); j++) {
            dp[j][0] = 1;
            for(int i = 1; i <= amount; i++) {
                dp[j][i] = dp[j - 1][i];
                if(i - coins[j - 1] >= 0)
                    dp[j][i] += dp[j][i - coins[j - 1]];
            }
        }
        return dp[coins.size()][amount];
    }
};
