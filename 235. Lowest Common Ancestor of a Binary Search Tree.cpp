//DFS
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if( (p->val - root->val)*(q->val - root->val) <= 0) return root;
        
        root = p->val > root->val ? root->right:root->left;
        
        return lowestCommonAncestor(root,p,q);
    }
};

//BFS
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        while((p->val - root->val)*(q->val - root->val) > 0)
        {
            root = p->val > root->val ? root->right:root->left;
        }
        return root;
    }
};