//DFS
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) 
    {
        vector<bool> visited(numCourses,false);
        
        vector<bool> onpath (numCourses,false);
        
        vector<unordered_set<int>> m(numCourses);
        
        vector<int> order;
        
        for(auto i : prerequisites)
        {
            m[i.first].insert(i.second);
        }
        
        for(int i = 0; i < numCourses; ++i)
        {
            if(visited[i]) continue;
            if(!check(i,visited,onpath,m,order)) return {};
        }
        
        return order;
    }
    
    bool check(int course,vector<bool>&visited, vector<bool> &onpath, vector<unordered_set<int>>&m,vector<int>&order)
    {
        if(visited[course]) return true;
        
        visited[course] = onpath[course] = true;
        
        for(int i : m[course])
        {
            if(onpath[i] || !check(i,visited, onpath, m, order)) return false;
        }
        
        order.push_back(course);
        
        onpath[course] = false;
        
        return true;
    }
};

//BFS
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) 
    {
        vector<vector<int>> graph(numCourses);
        
        vector<int> degree(numCourses,0);
        
        vector<int> order;
        
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
            
            order.push_back(tmp);
            
            for(int i : graph[tmp])
            {
                if(!--degree[i]) q.push(i);
            }
        }
        
        if(count != numCourses) return {};
        
        return order;
    }
};