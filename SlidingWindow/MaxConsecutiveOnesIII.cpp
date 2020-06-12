class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int i = 0, j = 0, res = INT_MIN, count = 0;
        for(; j < A.size(); j++) {
            if(A[j] == 0) count++;
            
            while(count > K && i < A.size()) {
                res = max(res, j - i);
                if(A[i] == 0)
                    count--;
                i++;
            }
        }
        res = max(res, j - i); 
        return res == INT_MIN ? ((count <= K ? A.size() : 0)) : res;
    }
};
