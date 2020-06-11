class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *tortoise = head;
        ListNode *hare = head;
        if(head == NULL || head->next == NULL)
            return NULL;
        int flag = 0;
        while(tortoise && hare) {
            tortoise = tortoise->next;
            if(hare->next == NULL) return NULL;
            hare = hare->next->next;
            if(tortoise == hare) {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            return NULL;
        tortoise = head;
        while(tortoise != hare) {
            tortoise = tortoise->next;
            hare = hare->next;
        }
        return hare;
    }
};
