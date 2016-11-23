/*Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1*/

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        if(!root) return root;

        swap(root->left, root->right);

        invertTree(root->left);

        invertTree(root->right);

        return root;
    }
};