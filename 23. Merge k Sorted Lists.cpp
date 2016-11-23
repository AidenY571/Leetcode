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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        return partition(lists, 0, lists.size()-1);
    }

    ListNode* partition(vector<ListNode*>& lists, int start, int end)
    {
        if (start > end) return NULL;
        else if (start == end) return lists[start];
        int mid = (start +end)/2;
        ListNode* a = partition(lists,start,mid);
        ListNode* b = partition(lists,mid+1,end);
        return merge(a,b);
    }

    ListNode* merge(ListNode* a, ListNode* b)
    {
        ListNode* head = new ListNode(0);
        ListNode* pass = head;
        while(a || b)
        {
            if(!a){pass->next = b; break;}
            if(!b){pass->next = a; break;}
            if(a->val < b->val)
            {
                pass->next = a;
                a = a->next;
            }
            else
            {
                pass->next = b;
                b = b->next;
            }
            pass = pass->next;
        }
        return head->next;
    }
};