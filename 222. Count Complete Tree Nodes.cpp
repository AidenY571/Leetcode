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
    int countNodes(TreeNode* root) 
    {
        if(!root)return 0;
        
        TreeNode* tmp = root;

        int height = 0, sum = 0,count=0;

        while(tmp){tmp=tmp->left;height++;}
        
        int level = height -2;
        
        while(level>=0) 
        {
            tmp = root->left;

            for(int i = 0;i < level; i ++) {tmp = tmp->right;}
            
            if(tmp)
            {
                root = root->right;
                count += (1 << level);
            } 

            else 
                root = root->left;

            level --;
        }

        if(root) count ++;

        return (1 << (height - 1)) + count - 1;
    }
};