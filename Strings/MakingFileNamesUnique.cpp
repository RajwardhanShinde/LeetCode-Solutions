class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> mp;
        vector<string> res(names.size());
        for(int i = 0; i < names.size(); i++) {
            if(mp.find(names[i]) != mp.end()) {
                int val = mp[names[i]];
                string str = names[i] + '(' + to_string(val) + ')';
                while(mp.find(str) != mp.end()) {
                    val++;
                    str = names[i] + '(' + to_string(val) + ')';
                }
                res[i] = str;
                mp[str] = 1;
                mp[names[i]] = val + 1;
            } else {
                res[i] = names[i];
                mp[names[i]] = 1;
            }
        }
        return res;
    }
};
