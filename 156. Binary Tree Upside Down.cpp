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
    TreeNode* upsideDownBinaryTree(TreeNode* root) 
    {
        if(!root)return root;
        
        stack<TreeNode*> s;

        while(root)
        {
            s.push(root);
            root = root->left;
        } 

        TreeNode* tmp = s.top();
        
        TreeNode* res = s.top();
        
        s.pop();
        
        while(!s.empty())
        {
            if(s.top()->right) tmp -> left = s.top()->right;

            tmp->right = s.top();

            tmp = tmp ->right;
            tmp -> right = NULL;
            tmp -> left = NULL;
            s.pop();
        }
        
        return res;

    }
};