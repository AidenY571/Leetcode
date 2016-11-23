/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//Merge Sort
class Solution {
public:
    ListNode* merge(ListNode*a, ListNode*b)
    {
        ListNode* head = new ListNode(0);
        ListNode* tmp = head;
        while(a || b)
        {
            if(b && (!a || a->val > b->val))
            {
                tmp = tmp->next = b;
                b = b->next;
            }
            if(a && (!b || a->val <= b->val))
            {
                tmp = tmp->next = a;
                a = a->next;
            }
        }
        tmp->next = NULL;
        return head->next;
    }

    ListNode* sortList(ListNode* head) 
    {
        if(!head || !head->next) return head;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* half = slow->next;

        slow->next = NULL;

        return merge(sortList(head),sortList(half));
    }
};

//Binary Sort
class Solution {
public:
    ListNode* sortList(ListNode* head) 
    {
        if (head == NULL || head->next == NULL) return head;
        
        ListNode* root = head;
        ListNode* end = root;
        ListNode* a = new ListNode(INT_MIN);
        ListNode* b = new ListNode(INT_MAX);
        ListNode* a1 = a;
        ListNode* b1 = b;

        int v = head->val;
        
        head = head->next;

        while(head != NULL)
        {
            if (head->val > v) 
            {
                a->next = head;
                a = a->next;
            }
            else if(head->val == v)
            {
                end->next = head;
                end = end->next;
            }
            else
            {
                b->next = head;
                b = b->next;
            }

            head = head->next;
        }
        a->next = NULL;
        
        b->next = NULL;
        
        end->next = NULL;
        
        if(a1->next != NULL) end->next = sortList(a1->next);
        
        if(b1->next != NULL)
        {
            ListNode* tmp = sortList(b1->next);
            
            ListNode* res = tmp;
            
            while(tmp->next!=NULL && tmp!=NULL)
            {
                tmp = tmp->next;
            }

            tmp->next = root;
            
            return res;
        }

         return root;
    }
};