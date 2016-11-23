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
    void reorderList(ListNode* head) 
    {
        if(!head || !head->next) return;
        
        ListNode *slow = head, *fast = head->next;
        
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        fast = slow->next;
        
        slow->next = NULL;
        
        ListNode *pre = new ListNode(0);
        
        while(fast)
        {
            auto p = pre->next;
            pre->next = fast;
            fast = fast->next;
            pre->next->next = p;
            
        }
        
        fast = pre->next;
        
        while(head && fast)
        {
            ListNode *tmp = fast;
            
            fast = fast->next;
            
            tmp->next = head->next;
            
            head->next = tmp;
            
            head = head->next->next;
        }
        
    }
};
