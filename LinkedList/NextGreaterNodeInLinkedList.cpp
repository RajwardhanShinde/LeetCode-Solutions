class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nums;
        ListNode *ptr = head;
        while(ptr) {
            nums.push_back(ptr->val);
            ptr = ptr->next;
        }
        vector<int> res(nums.size(), 0);
        stack<int> s;
        for(int i = 0; i < nums.size(); i++) {
            while(s.size() && nums[s.top()] < nums[i]) {
                res[s.top()] = nums[i];
                s.pop();
            } 
            s.push(i);
        }
        return res;
    }
};
