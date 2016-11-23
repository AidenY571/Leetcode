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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(!head)return head;
        
        int len = 1;

        ListNode* end = head;

        while(end->next){len++;end = end->next;}

        k = k%len;
        
        if(k==0) return head;
        
        ListNode*tmp = head;
        
        for(int i = 0; i < len - k-1; ++i){tmp = tmp->next;}

        ListNode* res = tmp->next;
        
        tmp->next =NULL;
        
        end->next = head;

        return res;

    }
};