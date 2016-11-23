class Solution {
public:
    int maxProfit(vector<int>& p) 
    {
        int buy = INT_MIN, sell = 0, pre_sell = 0;
        
        for(int i = 0; i < p.size();++i)
        {
            buy = max(pre_sell - p[i], buy);

            pre_sell = sell;

            sell = max(sell,p[i]+buy);
        }
        
        return sell;
    }
};