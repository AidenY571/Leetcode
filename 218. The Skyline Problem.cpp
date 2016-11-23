class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings)
    {
        vector<pair<int, int>> height,m;
        
        for(auto building : buildings)
        {
            m.push_back({building[0],-building[2]});
            m.push_back({building[1],building[2]});
        }
        
        sort(m.begin(),m.end());

        multiset<int>cur_hei;
        
        cur_hei.insert(0);
        for(auto i : m)
        {
            if(i.second > 0)
            {
                cur_hei.erase(cur_hei.find(-i.second));
            }
            else cur_hei.insert(i.second);
            
            if(height.empty() || *cur_hei.begin() != -height.back().second)
            {
                height.push_back({i.first,-*cur_hei.begin()});
            }
            
        }
        
        return height;
    }
};