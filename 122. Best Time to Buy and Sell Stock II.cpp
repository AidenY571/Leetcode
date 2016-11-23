class Solution {
public:
    int maxProfit(vector<int> &prices) 
    {
        int sum = 0;

        for (int i = 1; i < prices.size(); ++i)
        {
            int tmp = prices[i] - prices[i-1];
            sum += tmp > 0 ? tmp:0;
        }

        return sum;
    }
};