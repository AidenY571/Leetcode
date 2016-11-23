class Solution {
public:
    bool res = true;

    bool isBalanced(TreeNode* root) 
    {
        if(!root) return true;
        check(root);
        return res;
    }

    int check(TreeNode* root)
    {
        if(!root || !res) return 0;
        int l = check(root->left), r = check(root->right);
        if(abs(l-r) > 1) res = false;
        return max(l,r)+1;
    }

};