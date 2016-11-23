class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) 
    {
        vector<vector<int>> res;

        if(!root) return res;

        map<int,vector<int>>m;

        queue<pair<int,TreeNode*>> q;

        q.push({0,root});
        
        while(!q.empty())
        {
            auto tmp = q.front();
            q.pop();
            m[tmp.first].push_back(tmp.second->val);
            if(tmp.second->left)q.push({tmp.first-1,tmp.second->left});
            if(tmp.second->right)q.push({tmp.first+1,tmp.second->right});
            
        }
        
        for(auto it : m) res.push_back(it.second);
            
        return res;
    }
};