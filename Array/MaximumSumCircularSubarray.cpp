int kadane(vector<int> A, int i, int j, int sign) {
    int currsum = INT_MIN, best = INT_MIN;
    for(int k = i; k <= j; ++k) {
        currsum =  sign * A[k] + max(currsum , 0);
        best = max(best, currsum);
    }
    return best;
}

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        if(A.size() == 1)
            return A[0];
        int sum = 0;
        for(int x: A)
            sum += x;
        int ans = kadane(A, 0, A.size()-1, 1);
        int ans1 = sum + kadane(A, 1, A.size()-1, -1);
        int ans2 = sum + kadane(A, 0, A.size()-2, -1);
        return max({ans, ans1, ans2});
    }
};
