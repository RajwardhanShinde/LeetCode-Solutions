class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size() <= 2)
            return false;
        int i = 0;
        int n = A.size();
        while(i + 1 < n && A[i] < A[i + 1])
            i++;
        int j = n - 1;
        while(j > 0 && A[j - 1] > A[j])
            j--;
        return i > 0 && i == j && j < n - 1;
    }
};
