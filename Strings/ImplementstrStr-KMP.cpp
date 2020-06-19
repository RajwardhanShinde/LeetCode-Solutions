class Solution {
public:
    void computeLPSArray(string pat, int m, int* lps) {
        int len = 0;
        lps[0] = 0;
        
        int i = 1;
        while(i < m) {
            if(pat[i] == pat[len]) {
                //If Equal we store len at curr index
                lps[i++] = ++len;
            }
            else {
                //If not equal
                if(len != 0)
                    len = lps[len - 1];
                else {
                    //If len == 0
                    lps[i] = 0;
                    i++;
                }
            }
            
        }
        
    }
    
    int strStr(string txt, string pat) {
        // KMP algorithm
        int n = txt.length();
        int m = pat.length();
        
        if(!m)
            return 0;
        
        int lps[m];
        computeLPSArray(pat, m, lps);
        
        int i = 0;
        int j = 0;
        while(i < n) {
            if(pat[j] == txt[i]) 
                i++, j++;
            
            if(j == m) 
                return i - j;
            
            else if(i < n && pat[j] != txt[i]) {
                //move j 
                if(j != 0)
                    j = lps[j - 1];
                // inc i to find match with j if j == 0
                else
                    i++;
            }
        }
        return -1;
    }
};
