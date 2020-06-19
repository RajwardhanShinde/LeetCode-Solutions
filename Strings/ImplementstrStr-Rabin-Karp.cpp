class Solution {
public:
    int strStr(string source, string target) {
        // Rabin Karp algorithm
        int m = source.length();
        int n = target.length();
        if(m < n)
            return -1;
        long preCompute = 1;
        long hCode = 0;
        long tCode = 0;
        long d = 256;
        long q = 101;
        
        for(int i = 0; i < n - 1; i++)
            preCompute = (preCompute * d) % q;
        
        for(int j = 0; j < n; j++) {
            hCode = (hCode * d + source[j]) % q;
            tCode = (tCode * d + target[j]) % q;
        }
        
        for(int i = 0; i <= m - n; i++) {
            if(hCode == tCode) {
                int j = 0;
                for(; j < n; j++) {
                    if(source[i+j] != target[j])
                        break;
                }
                if(j == n)
                    return i;
            }
            if(i < m - n) {
                hCode = (d * (hCode - source[i] * preCompute) + source[i + n]) % q;
                if(hCode < 0)
                    hCode += q;
            }
        }
        return -1;
    }
};
