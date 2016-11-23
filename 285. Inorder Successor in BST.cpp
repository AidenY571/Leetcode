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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) 
    {
        TreeNode* res;
        
        if(!root || !p) return res;

        stack<TreeNode*> s;

        while(root)
        {
            s.push(root);
            root = root->left;
        }

        while(!s.empty())
        {
            res = s.top();

            s.pop();

            if(res->right)
            {
                TreeNode* tmp = res->right;
                while(tmp)
                {
                    s.push(tmp);
                    tmp = tmp->left;
                }
            }
            
            if(res->val == p->val) 
            {
                if(s.empty()) return NULL;
                return s.top();
            }
        }
        return NULL;
    }
}; 