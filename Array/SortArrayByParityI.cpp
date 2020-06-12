class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> even, odd;
        for(int i = 0; i < A.size(); i++) {
            if(A[i]%2 == 0)
                even.push_back(A[i]);
            else
                odd.push_back(A[i]);
        }
        vector<int> res = even;
        for(int i = 0; i < odd.size(); i++)
            res.push_back(odd[i]);
        return res;
    }
};
