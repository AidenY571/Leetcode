class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> tmp;
        while(!q.empty())
        {
            if(q.front()==NULL) 
            {
                res.push_back(tmp);
                q.pop();
                if(!q.empty())q.push(NULL);
                tmp.clear();
                continue;
            }
            tmp.push_back(q.front()->val);
            
            if(q.front()->left)q.push(q.front()->left);
            
            if(q.front()->right)q.push(q.front()->right);
            
            q.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {    
    	vector<vector<int>> v;
        
        vector<vector<int>> v1;
        
        if(root == NULL) return v;
        
        v = level(root,0,v);

        for (int i = 0; i < v.size(); ++i)
        {
        	v1.push_back(v[v.size()-1-i]);
        }
        return v1;
    }

    vector<vector<int>> level(TreeNode* root, int t, vector<vector<int>> v)
    {
    	vector<int> tmp;

    	if (v.size() <= t)
    	{
    		v.push_back(tmp);

    		v[t].push_back(root->val);
    	}
    	else
    	{
    		v[t].push_back(root->val);
    	}
    	

    	if (root->left != NULL)
    	{
    		v=level(root->left, t+1, v);
    	}
    	
    	if (root->right != NULL)
    	{
    		v=level(root->right, t+1, v);
    	}

    	return v;
    }
};