/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//Iteration
class Solution {
public:
    void flatten(TreeNode* root) 
    {
        if(root == NULL) return;

        stack<TreeNode*> s;

        if(root->right) s.push(root->right);

        if(root->left) s.push(root->left);

        while(!s.empty())
        {
            auto tmp = s.top();
            s.pop();
            if(tmp->right) s.push(tmp->right);
            if(tmp->left) s.push(tmp->left);
            root->right = tmp;
            root->left = NULL;
            root = root->right;
        }
        return;
    }
};

//Recursion
class Solution {
public:
    void flatten(TreeNode* root) 
    {
        if(!root) return;
        
        flatten(root->left);
        
        flatten(root->right);
        
        auto tmp = root->right;
        
        root->right = root->left;
        
        root->left = NULL;
        
        while(root->right) root = root->right;
        
        root->right = tmp;
    }
};