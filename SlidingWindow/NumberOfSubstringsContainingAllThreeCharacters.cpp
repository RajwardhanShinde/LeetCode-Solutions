class Solution {
public:
    int numberOfSubstrings(string s) {
        int freq[3] = {0};
        int j = 0, res = 0;
        for(int i = 0; i < s.length(); i++) {
            ++freq[s[i] - 'a'];
            while(freq[0] && freq[1] && freq[2]) {
                cout << "I:" << i << endl;
                --freq[s[j++] - 'a'];
            }
            cout << "J: " << j << endl;
            res += j;
        }
        return res;
    }
};
