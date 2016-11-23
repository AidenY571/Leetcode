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
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode* a = new ListNode(0);
        ListNode* b = new ListNode(0);
        ListNode* a1 = a;
        ListNode* b1 = b;

        while(head)
        {
            if(head->val >= x) 
            {
                b->next = head;
                b = b->next;
            }
            else
            {
                a->next = head; 
                a = a->next;
            }

            head = head->next;
        }

        a -> next = b1->next; 
        b->next = NULL;
        return a1->next;
    }
};