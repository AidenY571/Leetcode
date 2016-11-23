/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) 
    {
        if (root!= NULL && root->left != NULL)
        {
            root->left->next = root->right;

            if (root->next != NULL)
            {
                root->right->next = root->next->left;
            }
            connect(root->left);
            
            connect(root->right);
        }
        
    }
};

class Solution {
public: 
    void connect(TreeLinkNode *root) 
    {
        if(!root || !root->left) return;
        TreeLinkNode *next = root->left;
        
        while(root)
        {
            root->left->next = root->right;
            if(root->next) root->right->next = root->next->left;
            root = root->next;
        }
        connect(next);
    }
};