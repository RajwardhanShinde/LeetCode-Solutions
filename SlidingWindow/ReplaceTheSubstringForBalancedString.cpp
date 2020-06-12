class Solution {
public:
    int balancedString(string s) {
        int n = s.length();
        int bal = n / 4;
        unordered_map<char, int> mp;
        for(int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        int j = 0, res = n;
        for(int i = 0; i < n; i++) {
            mp[s[i]]--;
            while(j < n && mp['Q'] <= bal && mp['W'] <= bal && mp['E'] <= bal && mp['R'] <= bal) {
                res = min(res, i - j + 1);
                mp[s[j++]]++;
            }
        }
        return res;
    }
};
