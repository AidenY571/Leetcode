class Solution {
public:
    ListNode* insertionSortList(ListNode* head) 
    {
        ListNode* res= new ListNode(INT_MIN), *cur = res, *tmp;
        
        while(head)
        {   
            if(cur->val>head->val) cur = res;   //important
            
            while(cur->next && cur->next->val<head->val) cur = cur->next;
            
            tmp = head->next; 
            
            head->next = cur->next;
            
            cur->next =head;
            
            head = tmp;
        }
        return res->next;
    }
};