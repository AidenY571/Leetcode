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
    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
        vector<int>path;
        check(root,sum,path);
        return paths;
    }
    
    void check(TreeNode* root, int sum, vector<int>&path)
    {
        if(!root) return;
        
        sum -= root->val;
        
        path.push_back(root->val);
        
        if(!root->left && !root->right && !sum)
            paths.push_back(path);
        
        check(root->left,sum,path);
        
        check(root->right,sum,path);
        
        path.pop_back();
    }
    
private:
    vector<vector<int>>paths;
};