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
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
        ListNode* new_head = new ListNode(1);
        ListNode* pre = new_head;
        pre->next = head;
        ListNode* reverse_end;

        for(int i = 1; i < m; ++i) pre = pre->next;
        
        head = pre->next;
        
        reverse_end = head;
        
        for(int i = m; i <= n; ++i)
        {
            ListNode* tmp = head->next;
            head->next = pre->next;
            pre->next = head;
            head = tmp;
        }
        
        reverse_end->next = head;
        
        return new_head->next;
    }
};

class Solution {
public:
     ListNode* reverseBetween(ListNode* head, int m, int n)
     {
           ListNode* dummy = new ListNode(0);
           ListNode* pre = dummy;
           pre->next=head;

           for(int i=0;i<m-1;i++)pre=pre->next;

           ListNode* cur=pre->next;

           for(int i=0;i<n-m;i++)
           {
                 ListNode* tmp=cur->next;
                 cur->next=tmp->next;
                 tmp->next=pre->next;
                 pre->next=tmp;
           }
           
           return dummy.next;
    }
};