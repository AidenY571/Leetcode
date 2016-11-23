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
    int rob(TreeNode* root) 
    {   
        pair<int,int> v;
        
        v = helper(root,v);
        
        return v.first;
    }

    pair<int,int> helper(TreeNode* root, pair<int,int>v)
    {
        if (root== NULL) return v;
        
        pair<int,int> l = helper(root->left,v);
        
        pair<int,int> r = helper(root->right,v);
        
        v.first = max(l.second + r.second + root->val,l.first + r.first);
        
        v.second = l.first + r.first;
        
        return v;
    }
};