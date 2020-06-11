class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
            return NULL;
        ios::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
        ListNode *one = head;
        ListNode *two = head->next;
        ListNode *dummy = head->next;
        while(one && two && one->next && two->next){
            one->next = one->next->next;
            one = one->next;
            two->next = two->next->next;
            two = two->next;
        }
        one->next = dummy;
        return head;
    }
};
