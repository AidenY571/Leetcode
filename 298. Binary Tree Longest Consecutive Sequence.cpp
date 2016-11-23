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
    int longestConsecutive(TreeNode* root) 
    {
        if(!root) return 0;

        int res = 0;

        check(root, root->val-1,0,res);

        return res;
    }

    void check(TreeNode* root, int pre, int len, int &res)
    {
        if(!root) return;

        if(root->val-1 == pre) 
        {
            ++len;
            res = max(len,res);
        }
        else
            len = 1;

        check(root->left,root->val,len,res);
        check(root->right,root->val,len,res);
    }
};