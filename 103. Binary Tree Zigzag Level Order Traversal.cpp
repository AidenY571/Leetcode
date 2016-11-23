class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> order;
        
        if(!root) return order;
        
        stack<TreeNode*> s;
        
        s.push(root);
        
        bool l = true;
        
        while(!s.empty())
        {
            vector<int> cur_lvl;
            
            stack<TreeNode*> new_s;
            
            while(!s.empty())
            {
                if(l && s.top()->left) new_s.push(s.top()->left);

                if(s.top()->right) new_s.push(s.top()->right);

                if(!l && s.top()->left) new_s.push(s.top()->left);

                cur_lvl.push_back(s.top()->val);

                s.pop();
            }
            order.push_back(cur_lvl);

            s = new_s;
            
            l = !l;
        }
        
        return order;
    }
};

// by reverse
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> res;

        check(root,0,res);

        for (int i = 1; i < res.size(); i += 2)
        {
            reverse(res[i].begin(),res[i].end());
        }

        return res;
    }

    void check(TreeNode* root, int lvl, vector<vector<int>>&res)
    {
        if(!root) return;

        if(res.size()==lvl) res.push_back({root->val});
        else
            res[lvl].push_back(root->val);

        check(root->left,lvl+1,res);

        check(root->right,lvl+1,res);

        return;
    }

};