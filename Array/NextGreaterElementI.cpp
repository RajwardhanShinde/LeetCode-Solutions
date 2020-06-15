class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> s;
        for(int n: nums2) {
            while(s.size() && s.top() < n) {
                mp[s.top()] = n;
                s.pop();
            }
            s.push(n);
        }
        vector<int> res(nums1.size(), - 1);
        for(int i = 0; i < nums1.size(); i++) {
            auto itr = mp.find(nums1[i]);
            if(itr != mp.end())
                res[i] = mp[nums1[i]];
        }
        return res;
    }
};
