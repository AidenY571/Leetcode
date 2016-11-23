class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) 
    {
        if(n==1) return {0};
        vector<vector<int>> graph(n);
        
        vector<int> degree(n,0);
        
        vector<int> res;
        
        for(auto i : edges)
        {
            graph[i.first].push_back(i.second);
            graph[i.second].push_back(i.first);
            ++degree[i.first]; ++degree[i.second];
        }
        
        queue<int> q;
        
        for(int i = 0; i < n; ++i)
        {
            if(degree[i]==1)
            {
                degree[i]--;
                q.push(i);
            }
        }
        
        while(n > 2)
        {
            int len = q.size();
            
            for(int i = 0; i < len;++i)
            {
                int tmp = q.front();
            
                q.pop();
                
                --n;
                
                for(int i : graph[tmp])
                {
                    if(--degree[i]==1) q.push(i);
                }
            }
        }
        
        while(!q.empty())
        {
            res.push_back(q.front());
            q.pop();
        }
        
        return res;
    }
};