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
    int kthSmallest(TreeNode* root, int k) 
    {
        stack<TreeNode*> s;
        
        while(root || !s.empty())
        {
            while(root)
            {
                s.push(root);
                root = root->left;
            }
            
            if(--k == 0) return s.top()->val;
            
            root = s.top()->right;
            
            s.pop();
        }
        
        return 0;
    }
};