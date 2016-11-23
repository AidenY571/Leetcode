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
    vector<vector<int>> findLeaves(TreeNode* root) 
    {
        vector<vector<int>> res;
        
        if(!root) return res;

        while(root->left || root->right)
        {
            vector<int>tmp;
            check(root,NULL,tmp);
            res.push_back(tmp);
        }
        res.push_back({root->val});
        return res;
    }

    void check(TreeNode* root, TreeNode*p,vector<int>&v)
    {
        if(!root->left && !root->right)
        {
            v.push_back(root->val);
            p->left == root ? p->left = NULL : p->right = NULL;
            return;
        }
        if(root->left) check(root->left,root,v);

        if(root->right) check(root->right,root,v);

        return;
    }
};