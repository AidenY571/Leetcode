//DFS
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) 
    {
        vector<bool> visited(numCourses,false);
        
        vector<bool> onpath(numCourses,false);
        
        vector<unordered_set<int>> m(numCourses);
        
        for(auto i : prerequisites) m[i.first].insert(i.second);
        
        for(int i = 0; i < numCourses; ++i)
        {
            if(visited[i] || m[i].empty()) continue;
            if(!check(i,visited,onpath,m)) return false;
        }
        
        return true;
    }
    
    bool check(int node, vector<bool> &visited,vector<bool>&onpath,vector<unordered_set<int>> &m)
    {
        if(onpath[node]) return false;
        
        if(visited[node]) return true;
        
        visited[node] = onpath[node] = true;
        
        for(auto i:m[node])
        {
            if(!check(i,visited,onpath,m)) return false;
        }
        
        onpath[node] = false;
        
        return true;
    }
};

//BFS
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) 
    {
        vector<vector<int>> graph(numCourses);
        
        vector<int> degree(numCourses,0);
        
        for(pair<int, int> i : prerequisites)
        {
            graph[i.second].push_back(i.first);
            ++degree[i.first];
        }
        
        int count = 0;
        
        queue<int> q;
        
        for(int i = 0; i < numCourses; ++i)
        {
            if(!degree[i])
            q.push(i);
        }
        
        while(!q.empty())
        {
            int tmp = q.front();
            
            q.pop();
            
            ++count;
            
            for(int i : graph[tmp])
            {
                if(!--degree[i]) q.push(i);
            }
        }
        
        return count == numCourses;
    }
};