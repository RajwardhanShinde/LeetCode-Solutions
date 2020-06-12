class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int i = 0, j = 0, n = tree.size(), res=INT_MIN;
        unordered_map<int, int> mp;
        for(; i < tree.size(); i++) {
            mp[tree[i]]++;
            while(j < n && mp.size() > 2) {
                res = max(res, i - j);
                mp[tree[j]]--;
                if(mp[tree[j]] == 0)
                    mp.erase(tree[j]);
                j++;
            }
        }
        res = max(res, i - j);
        return res == INT_MIN ? (mp.size() > 0 ? n : 0) : res;
    }
};
