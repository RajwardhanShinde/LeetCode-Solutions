class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL) 
            return l1;
        ListNode *head = NULL, *tail = NULL;
        while(l1 != NULL && l2 != NULL) {
            ListNode *ptr;
            if(l1->val <= l2->val) {
                ptr = new ListNode(l1->val);
                if(head == NULL) {
                    head = ptr;
                    tail = ptr;
                } else {
                    tail->next = ptr;
                    tail = ptr;
                }
                l1 = l1->next;
            }
            else {
                ptr = new ListNode(l2->val);
                if(head == NULL) {
                    head = ptr;
                    tail = ptr;
                } else {
                    tail->next = ptr;
                    tail = ptr;
                }
                l2 = l2->next;
            }
        }
        ListNode *rem;
        while(l1) {
            rem = new ListNode(l1->val);
            tail->next = rem;
            tail = rem;
            l1 = l1->next;
        }
        while(l2) {
            rem = new ListNode(l2->val);
            tail->next = rem;
            tail = rem;
            l2 = l2->next;
        }
        return head;
    }
};
