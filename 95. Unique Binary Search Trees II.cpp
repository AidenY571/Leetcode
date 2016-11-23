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
    vector<TreeNode*> generateTrees(int n) 
    {   
        if(n==0) return {};
      
        return check(1,n);       
    }

    vector<TreeNode*> check(int begin, int end)
    {
        if(begin>end) return {NULL};    //empty tree !important!
    
        vector<TreeNode*> res;
        
        for (int i = begin; i <= end; ++i)
        {
            vector<TreeNode*> left = check(begin,i-1);

            vector<TreeNode*> right = check(i+1,end);
            
            for(TreeNode*k : left)for (TreeNode*m : right)
            {
                    TreeNode* tmp = new TreeNode(i);
                    tmp->left = k;
                    tmp->right = m;
                    res.push_back(tmp);

            }
        }
        return res;
    }
};
