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
    int maxPathSum(TreeNode* root) 
    {
        int t = check(root);
        return maxsum;
    }
    
    int check(TreeNode* root)
    {
        if(!root) return 0;

        int lsum = check(root->left);

        int rsum = check(root->right);

        int tmp = root->val;

        if(lsum > 0) tmp += lsum;

        if(rsum > 0) tmp += rsum;

        maxsum = max(maxsum,tmp);
        
        return max(root->val,max(lsum,rsum)+root->val);
    }
private:
int maxsum = INT_MIN;
};