class Solution {
public:
    int minSetSize(vector<int>& arr) {
        //int freq[100000] = {0};
        unordered_map<int, int> mp; 
        int n = arr.size();
        int mid = n / 2;
        for(int i = 0; i < n; i++) {
            //freq[arr[i]]++;
            mp[arr[i]]++;
        }
        vector<int> v;
        for(auto x: mp) {
            v.push_back(x.second);
        }
        sort(v.begin(), v.end());
        int currSize = 0, idx = 0, count = 0;
        if(v.size() == 1)
            return 1;
        for(int i = v.size() - 1; i >= 0; i--) {
            currSize += v[i];
            if(currSize >= mid) {
                count = v.size() - i;
                break;
             }
        }
        return count;
    }
};
