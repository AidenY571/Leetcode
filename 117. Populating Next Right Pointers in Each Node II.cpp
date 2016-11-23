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
        if(!root) return;
        
        TreeLinkNode* next = new TreeLinkNode(0);
        
        TreeLinkNode* pass = next;
        
        while(root)
        {
            if(root->left)
            {
                pass->next = root->left;
                pass = pass->next;
            }
            
            if(root->right)
            {
                
                pass->next = root->right;
                pass = pass->next;
            }
            
            root = root->next;
        }
        
        connect(next->next);
        
        delete next;
      
    }
};