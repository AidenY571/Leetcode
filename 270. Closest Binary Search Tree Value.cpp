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
    int closestValue(TreeNode* root, double target) 
    {
        int tmp = root->val;

        while(root)
        {
            if (abs(tmp - target) >= abs(root->val - target)) tmp = root->val;

            root->val > target ? root = root->left : root = root->right;
        }
        
        return tmp;
    }
};