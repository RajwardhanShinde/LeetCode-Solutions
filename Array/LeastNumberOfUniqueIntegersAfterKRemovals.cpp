class Solution {
public:
    
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp; 
        for(int i = 0; i < arr.size(); i++) {
            mp[arr[i]]++;
        }
        vector<pair<int,int>> values(mp.begin(),mp.end());
        auto cmp = [](const pair<int,int>& l, pair<int,int>& r) { return l.second < r.second;};
        sort(values.begin(),values.end(),cmp);
        int count = 0;
        for(auto it = values.begin(); it != values.end(); it++) {
            while(k > 0 && it->second > 0) {
                it->second--;
                k--;
            }
            
            if(it->second <= 0)
                count++;
            
            if(k <= 0)
                break;
        }
        return mp.size() - count;
    }
};
