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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode* n;
    Solution(ListNode* head) {
        n = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() 
    {
        ListNode* node = n->next;
        int num = n->val, index = 2;
        
        while(node)
        {
            int tmp = rand()%index;
            if(tmp==0) num = node->val;
            node = node->next;
            ++index;
        }
        
        return num;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */