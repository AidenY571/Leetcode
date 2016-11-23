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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode* new_head = new ListNode(1);
        
        ListNode* pass = new_head;
        
        while(head)
        {
            int val = head->val;
            
            if(head->next && head->next->val == val)
            {
                while(head && head->val == val) head = head->next;
            }
            else
            {
                pass->next = head;
                pass = pass->next;
                head = head->next;
            }
        }
        pass->next = NULL;
        return new_head->next;
    }
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode* pass = new ListNode(1);

        ListNode* res = pass;
        
        while(head)
        {
            ListNode* tmp = head->next;

            while(tmp && tmp->val == head->val)
                tmp = tmp->next;

            if(tmp == head->next)
            {
                pass->next = head;
                pass = pass->next;
            }

            head = tmp;
        }

        pass->next = NULL;
        return res->next;
    }
};