/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//iteration
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* tmp = NULL;

        ListNode* post;
            
        while(head)
        {   
            post = head->next;

            head->next = tmp;

            tmp = head;

            head = post;
        }

        return tmp;
    }
};

//recursion
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        return reverse(NULL,head);
    }

    ListNode* reverse(ListNode* pre, ListNode* cur)
    {
        if(!cur) return pre;
        ListNode* tmp = cur->next;
        cur->next = pre;
        return reverse(cur,tmp);
    }
};