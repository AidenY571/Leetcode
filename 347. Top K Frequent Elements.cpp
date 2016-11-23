class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int,int> map;
        
        for(int num : nums) map[num]++;

        vector<int> res;

        priority_queue<pair<int,int>> pq; 

        for(auto it: map)
        {
            pq.push(make_pair(it.second, it.first));

            if(pq.size()+k > (int)map.size())
            {
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        
        return res;
    }
};