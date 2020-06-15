class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        if(arr.size() == 1)
            return arr;
        sort(arr.begin(), arr.end());
        vector<int> res;
        int n = arr.size();
        int median = arr[(n -  1) / 2];
        int i = 0, j = n - 1;
        while(i <= j && res.size() < k) {
            if(abs(arr[i] - median) > abs(arr[j] - median)) {
                res.push_back(arr[i]);
                i++;
            }
            else if(abs(arr[i] - median) == abs(arr[j] - median)) {
                if(arr[i] > arr[j]) {
                    res.push_back(arr[i]);
                    i++;
                }
                else { 
                    res.push_back(arr[j]);
                    j--;
                }
            }
            else {
                res.push_back(arr[j]);
                j--;
            }
        }
        return res;
    }
};
