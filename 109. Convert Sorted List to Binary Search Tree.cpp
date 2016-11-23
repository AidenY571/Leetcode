/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) 
    {
        if(!head) return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = NULL;
        while(fast->next && fast->next->next)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        TreeNode* root = new TreeNode(slow->val);
        
        if(pre) 
        {
            pre->next = NULL;
            root->left = sortedListToBST(head);
        }
        root->right = sortedListToBST(slow->next);
        return root;
    }
};