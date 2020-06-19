class Solution {
public:
    bool check(vector<int>& v, int m, int k, int mid) {
        int c = 0, tot = 0;
        for(int i = 0; i < v.size(); i++) {
            if(v[i] <= mid) {
                c++;
                if(c == k) {
                    tot++;
                    c = 0;
                }
            }
            else
                c = 0;
        }
        if(tot >= m) return true;
        return false;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int ans = -1;
        int low =  0, high = INT_MAX - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(check(bloomDay, m, k, mid)) { 
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};
