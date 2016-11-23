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
    bool isValidBST(TreeNode* root) 
    {
        TreeNode *pre = NULL;
        return check(root, pre);
    }
    
    bool check(TreeNode* root, TreeNode* &pre)
    {
        if(!root) return true;
        
        if(!check(root->left,pre)) return false;
        
        if(pre && root->val <= pre->val) return false;
        
        pre = root;
        
        return check(root->right,pre);
    }
    
};