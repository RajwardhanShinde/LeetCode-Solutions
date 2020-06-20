class Solution {
public:
    void computeLPSArray(string pat, int m, int* lps) {
        int len = 0;
        lps[0] = 0;
        int i = 1;
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
    
    int repeatedStringMatch(string A, string B) {
        int n = A.size();
        int m = B.size();
        
        int lps[m];
        computeLPSArray(B, m, lps);
        
        int i = 0, j = 0;
        while(i < n) {
            while(j < m && A[(i + j) % n] == B[j]) {
                j++;
            }
            
            if(j == m) 
                return ceil((float)(i + j) / n);
            
            i++;
            
            if(j > 0)
                j = lps[j - 1];
        }
        return -1;
    }
};
