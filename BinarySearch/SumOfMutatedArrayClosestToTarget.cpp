class Solution {
public:
    int check(int mid, vector<int> arr, int target) {
        int sum = 0;
        for(int i = 0; i < arr.size(); i++)
            sum += min(arr[i], mid);
        return abs(sum - target);
    }
    
    int findBestValue(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;
        while(low < high) {
            int mid = (low + high) >> 1;
            if(check(mid, arr, target) <= check(mid + 1, arr, target)) 
                high = mid;
            else 
                low = mid + 1;
        }
        return arr[low];
    }
};
