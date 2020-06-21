class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, n = nums1.size(), m = nums2.size();
        vector<int> arr;
        while(i < n && j < m) {
            if(nums1[i] > nums2[j])
                arr.push_back(nums2[j++]);
            else
                arr.push_back(nums1[i++]);
        }
        while(i < n)
            arr.push_back(nums1[i++]);
        while(j < m)
            arr.push_back(nums2[j++]);
        int len = n + m;
        if(len % 2 == 0) {
            int mid = len / 2;
            return (double)(arr[mid] + arr[mid - 1]) / 2;
        }
        int mid = len / 2;
        return arr[mid];
    }
};
