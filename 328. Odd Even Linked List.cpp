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
    ListNode* oddEvenList(ListNode* head) 
    {
        ListNode* odd = new ListNode(1);

        ListNode* evenhead = new ListNode(0);

        ListNode* even = evenhead, *res = head;
        
        while(head)
        {
            odd->next = head;
            odd = odd->next;
            head = head->next;
            if(head)
            {
                even ->next = head;
                even = even->next;
                head = head->next;
            }
        }
        
        even->next = NULL;
        
        odd->next =evenhead->next;
        
        return res;
    }
};