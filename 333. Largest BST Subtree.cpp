class Solution {
public:
    int largestBSTSubtree(TreeNode* root) 
    {
        int num = 0, min_v = INT_MAX, max_v =INT_MIN;
        bool is_bst = false;
        check(root,is_bst,min_v,max_v,num);
        return num;
    }

    void check(TreeNode* root, bool &is_bst, int &min_v, int &max_v, int &num)
    {
        if(root == NULL)
        {
            is_bst = true;
            num = 0;
            min_v = INT_MAX;
            max_v = INT_MIN;
            return;
        }
        
        int num_L = 0, num_R = 0, min_L = INT_MAX, min_R = INT_MAX, max_L = INT_MIN, max_R = INT_MIN;
        bool is_bstL = false,is_bstR = false;
        
        check(root->left,is_bstL,min_L,max_L,num_L);
        check(root->right,is_bstR,min_R,max_R,num_R);
        
        if(is_bstL && is_bstR && max_L <= root->val && min_R > root->val)
        {
            is_bst= true;
            min_v = min(min_L,root->val);
            max_v = max(max_R,root->val);
            num = num_L + num_R + 1;
        }
        else
        {
            is_bst = false;
            num = max(num_L,num_R);
        }

    }
};