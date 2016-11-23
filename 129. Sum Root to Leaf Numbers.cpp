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
    int sumNumbers(TreeNode* root) 
    {
        if(root == NULL) return 0;

        int res = 0;

        check(root, 0 , res);

        return res;
    }

    void check(TreeNode*root, int n,int &res)
    {
        n = n*10 + root->val;

        if(root->left == NULL && root->right==NULL) res += n;
        
        if(root->left != NULL) check(root->left,n,res);

        if(root->right != NULL) check(root->right,n,res);

        return;
    }
};