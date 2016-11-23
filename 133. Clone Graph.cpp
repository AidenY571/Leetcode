/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

// DFS 
class Solution {
public:
    unordered_map<int,UndirectedGraphNode*> m;

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) 
    {
        if(!node) return node;
        
        if(m.find(node->label)!=m.end()) return m[node->label];

        UndirectedGraphNode* n = new UndirectedGraphNode(node->label);

        m[n->label] = n;

        for (auto i : node->neighbors) n->neighbors.push_back(cloneGraph(i));
        
        return n; 
    }
};

///BFS
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) 
    {
        if(!node) return NULL;
        unordered_map<int,UndirectedGraphNode*> m;

        queue<UndirectedGraphNode*> q;
        
        q.push(node);

        while(!q.empty())
        {
            int len = q.size();

            for (int i = 0; i < len; ++i)
            {
                if(m.find(q.front()->label)==m.end())
                {
                    UndirectedGraphNode* new_node = new UndirectedGraphNode(q.front()->label);
                    m[q.front()->label] = new_node;
                }
                
                UndirectedGraphNode* new_node = m[q.front()->label];

                {
                    if(m.find(n->label)==m.end())
                    {
                        UndirectedGraphNode* t = new UndirectedGraphNode(n->label);
                        m[n->label] = t;
                        q.push(n);
                    }

                    new_node->neighbors.push_back(m[n->label]);
                }

                m[q.front()->label] = new_node;
                
                q.pop();
            }
        }

        return m[node->label];
    }
};