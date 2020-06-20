class Solution {
public:
    void computeLPSArray(string pat, int m, int* lps) {
        int len = 0;
        int i = 1;
        lps[0] = 0;
        while(i < m) {
            if(pat[i] == pat[len])
                lps[i++] = ++len;
            else {
                if(len == 0) {
                    lps[i] = 0;
                    i++;
                } else
                    len = lps[len - 1];
            }
        }
    }
    
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        int lps[n];
        computeLPSArray(s, n, lps);
        return lps[n - 1] && n % (n - lps[n - 1]) == 0;
    }
};
