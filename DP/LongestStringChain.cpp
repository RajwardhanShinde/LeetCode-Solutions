class Solution {
public:
    static bool compare(const string &s1, const string &s2) {
        return s1.length() < s2.length();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), compare);
        unordered_map<string, int> dp;
        int res = 0;
        for (string s : words) {
            for (int i = 0; i < s.length(); i++)
                dp[s] = max(dp[s], dp[s.substr(0, i) + s.substr(i + 1)] + 1);
            res = max(dp[s], res);
        }
        return res;
    }
};