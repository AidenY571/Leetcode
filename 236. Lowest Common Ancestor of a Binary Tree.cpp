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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(!root || root == p || root == q) return root;

        TreeNode* l = lowestCommonAncestor(root->left,p,q);
        
        TreeNode* r = lowestCommonAncestor(root->right,p,q);
        
        return l ? (r? root : l) : r;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        auto inorder_p = check(root,p);
        auto inorder_q = check(root,q);
        
        for (int i = 0; i <= min(inorder_p.size(),inorder_q.size()); ++i)
        {
            if(inorder_p[i] != inorder_q[i] || i ==  min(inorder_p.size(),inorder_q.size())) 
                return inorder_p[i-1];
        }
        return root;
    }

    vector<TreeNode*> check(TreeNode* root, TreeNode* p)
    {
        if(root == NULL) return {};

        if(root == p) {vector<TreeNode*> v(1,root);return v;}

        vector<TreeNode*> l = check(root->left,p);
        vector<TreeNode*> r = check(root->right,p);
        if(l.size()!=0){l.insert(l.begin(),root); return l;}
        if(r.size()!=0){r.insert(r.begin(),root); return r;}
        return {};
    }
};
