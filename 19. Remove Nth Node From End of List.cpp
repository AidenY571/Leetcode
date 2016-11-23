class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* res = new ListNode(1);
        res->next = head;
        ListNode* pre = res;

        while(--n) head = head->next;

        while(head->next)
        {
            pre = pre->next;
            head = head->next;
        }

        pre->next = pre->next->next;

        return res->next;
    }
};
