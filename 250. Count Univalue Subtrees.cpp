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
    int res = 0;
    int countUnivalSubtrees(TreeNode* root) 
    {
        bool t = check(root);
        return res;
    }

    bool check(TreeNode* root)
    {
        if(!root) return true;

        if(!root->left && !root->right)
        {
            res++;
            return true;
        }

        if(root->left && root->val != root->left->val) return false;

        if(root->right && root->val != root->right->val) return false;

        if(check(root->left) && check(root->right))
        {
            res++;
            return true;
        }

        return false;
    }
};