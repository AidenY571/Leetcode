class Solution {
public:
    int minCost(vector<vector<int>>& costs) 
    {
        if(costs.empty()) return 0;
        int a = costs[0][0], b = costs[0][1], c = costs[0][2];

        for (int i = 1; i < costs.size(); ++i)
        {
            int a1 = min(b,c) + costs[i][0];
            int b1 = min(a,c) + costs[i][1];
            int c1 = min(a,b) + costs[i][2];
            a = a1; b = b1; c = c1;
        }
        return min(a,min(b,c));
    }
};