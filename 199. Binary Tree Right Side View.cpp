/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //BFS
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> res;

        if(!root) return res;

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty())
        {
            int len = q.size();

            for (int i = 0; i < len; ++i)
            {
                TreeNode* tmp = q.front();

                if(!i) res.push_back(tmp->val);

                if(tmp->right) q.push(tmp->right);

                if(tmp->left) q.push(tmp->left);
                
                q.pop();
            }
        }
        return res;
    }
};

//DFS
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        check(root,0);
        return res;
    }

    void check(TreeNode* root, int length)
    {
        if(!root) return;
        
        if(length == res.size())
            res.push_back(root->val);
        
        check(root->right,length+1);
        
        check(root->left, length+1);
    }
private:
    vector<int> res;
};