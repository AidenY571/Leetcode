class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) 
    {
        int small = INT_MAX, large = INT_MIN;

        unordered_map<int,set<int>>m;

        for(int i = 0; i < points.size();++i)
        {
            small = min(small, points[i].first);
            large = max(large, points[i].first);
            m[points[i].second].insert(points[i].first);
        }

        int mid = small+large;
        
        for (auto it = m.begin(); it!=m.end(); ++it) 
        {
            for (auto start=it->second.begin(), end = it->second.end(); start!=end; ++start) 
            {
                if ((*start + *(--end)) != mid) return false;
                if (start==end) break;
            }   
        }
        return true;
    }
};