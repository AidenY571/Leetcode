class Solution {
public:
    bool isSymmetric(TreeNode* root) 
    {
        if(!root) return true;
        return check(root->left,root->right);
    }
    
    bool check(TreeNode* a, TreeNode* b)
    {
        if(!a && !b) return true;
        if(!a || !b) return false;
        if(a->val == b->val)
        {
            return check(a->left,b->right) && check(a->right,b->left);
        }
        return false;
    }
};