/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) 
    {
        ListNode* pre = new ListNode(1);

        ListNode* res = pre;

        while(head && head->next)
        {
            ListNode* tmp = head->next->next;

            pre->next = head->next;

            pre->next->next = head;

            pre = pre->next->next;

            head = tmp;
        }

        if(head) {pre->next = head; pre = pre->next;}

        pre->next = NULL;
        return res->next;
    }
};