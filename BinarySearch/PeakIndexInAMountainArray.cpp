class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int low = 0, high = A.size() - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if((A[mid] > A[mid - 1] && A[mid] > A[mid + 1]))
                return mid;
            else if(A[mid] < A[mid + 1])
                low = mid + 1;
            else 
                high = mid - 1;
        }
        return low;
    }
};
