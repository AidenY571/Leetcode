//BFS
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) 
    {
        queue<int> q;
        vector<vector<int>> t(n);
        for(auto i:edges)
        {
            t[i.first].push_back(i.second);
            t[i.second].push_back(i.first);
        }
        int v[n]={0};
        v[0] = 1;
        q.push(0);

        while(!q.empty())
        {
            for(auto i : t[q.front()])
            {
                if(v[i] == 1) return false;
                if(v[i] == 0) {q.push(i);v[i]++;}
            }
            v[q.front()] = 2;
            q.pop();
        }

        for(int i : v)
        {
            if(!i) return false;
        }

        return true;
    }
};

//DFS
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) 
    {
        vector<vector<int>> t(n);
        
        for(auto i:edges)
        {
            t[i.first].push_back(i.second);
            t[i.second].push_back(i.first);
        }
        
        vector<int> v (n,0);
        
        if(check(t, v, 0, -1)) return false;
        
        for(int i:v)
        {
            if(!i) return false;
        }
        
        return true;
    }

    bool check(vector<vector<int>> &t, vector<int> &v, int num, int pre)
    {
        v[num]++;
        for(auto i : t[num])
        {
            if(i == pre) continue;
            
            if(v[i] == 1) return true;

            if(!v[i] && check(t, v, i, num)) return true;
        }

        return false;
    }
};

// Union Find
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) 
    {
        vector<int> nodes(n,0);
        
        for(int i=0; i<n; i++) nodes[i] = i;
        
        for(int i=0; i<edges.size(); i++)
        {
            int f = edges[i].first, s = edges[i].second
            
            while(nodes[f]!=f) f = nodes[f];
            
            while(nodes[s]!=s) s = nodes[s];
            
            if(nodes[f] == nodes[s]) return false
            
            nodes[s] = f;
        }
        return edges.size() == n-1;
    }
};