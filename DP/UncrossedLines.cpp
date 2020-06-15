class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size(), dp[n+1][m+1];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++) 
            for(int j = 1; j <= m; j++)
                dp[i][j] = A[i - 1] == B[j - 1] ? dp[i - 1][j - 1] + 1: max(dp[i][j - 1], dp[i - 1][j]);
        return dp[n][m];
    }
};
