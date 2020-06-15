class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> nums1, nums2;
        while(l1) {
            nums1.push_back(l1->val);
            l1 = l1->next;
        }
        
        while(l2) {
            nums2.push_back(l2->val);
            l2 = l2->next;
        }
        
        int i = nums1.size() - 1, j = nums2.size() - 1, carry = 0, sum = 0;
        ListNode *head = NULL, *ptr = NULL;
        while(i >= 0 || j >= 0 || carry > 0) {
            sum = carry;
            if(i >= 0)
                sum += nums1[i];
            
            if(j >= 0)
                sum += nums2[j];
            
            carry = sum / 10;
            ptr = new ListNode(sum % 10);
            ptr->next = head;
            head = ptr;
            i--, j--;
        }
       return head; 
    }
};
