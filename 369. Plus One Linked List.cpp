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
    ListNode* plusOne(ListNode* head) 
    {
        stack<ListNode*> s;

        ListNode* tmp = head;

        int carry = 1;

        while(tmp)
        {
            s.push(tmp);
            tmp=tmp->next;
        }

        while(carry && !s.empty())
        {
            int tmp = s.top()->val + 1;
            s.top()->val = tmp % 10;
            carry = tmp/10;
            s.pop();
        }
        
        if(carry)
        {
            ListNode* res = new ListNode(1);
            res->next = head;
            return res;
        }
        return head;
    }
};