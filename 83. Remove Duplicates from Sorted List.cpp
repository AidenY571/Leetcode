/*Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
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
    ListNode* deleteDuplicates(ListNode* head) {
    ListNode *cur = head;
    while (cur && cur->next) {
        if (cur->val == cur->next->val)
            cur->next = cur->next->next;
        else
            cur = cur->next;
    }
    return head;
}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) 
    {
        if(head == NULL) return NULL;
        
        ListNode *tmp = head;
        ListNode *res = tmp;
        head=head->next;
    
        while (head != NULL)
        {
            if (tmp -> val != head->val)
            {
                tmp->next = head;
                tmp = tmp->next;
            }
            
            head = head->next;
        }
        
        tmp->next = NULL;
        
        return res;
    }
};