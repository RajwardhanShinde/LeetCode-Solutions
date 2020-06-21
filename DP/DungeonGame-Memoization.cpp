class Solution {
public:
    int solve(vector<vector<int>>& arr, vector<vector<int>>& dp, int i, int j, int n, int m) {
        if(i == n - 1 && j == m - 1)
            return arr[i][j] > 0 ? 1 : abs(arr[i][j]) + 1;
        
        if(dp[i][j] != - 1)
            return dp[i][j];
        
        if(i == n - 1 || j == m - 1) {
            return i == n - 1 ? max(1, solve(arr, dp, i, j + 1, n, m) - arr[i][j]) :
                                max(1, solve(arr, dp, i + 1, j, n, m) - arr[i][j]);
        }
        
        return dp[i][j] = max(1, min(solve(arr, dp, i + 1, j, n, m) - arr[i][j], solve(arr, dp, i, j + 1, n, m) - arr[i][j]));
    }
    
    int calculateMinimumHP(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(arr, dp, 0, 0, n, m);
    }
    
};


