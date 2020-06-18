//Binary Search
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int low = 0, high = n - 1;
        while(low <= high) {
            int mid = (low + high) >> 1;
            if(citations[mid] == n - mid) 
                return citations[mid];
            else if(citations[mid] > (n - mid))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return n - low;
    }
};

//Counting Sort
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> count(n + 1, 0);
        for(int i = 0; i < n; i++) {
            if(citations[i] >= n)
                count[n]++;
            else
                count[citations[i]]++;
        }
        int h_index = 0;
        for(int i = n; i >= 0; i--) {
            h_index += count[i];
            if(h_index >= i)
                return i;
        }
        return 0;
    }
};
