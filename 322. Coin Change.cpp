class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<int> v(amount+1,amount+1);

        v[0] = 0;

        for(int k:coins)
        {
            for (int i = k; i <= amount; ++i)
            {
                v[i] = min(v[i],v[i-k]+1);
            }
        }

        if(v[amount]==amount+1) return -1;

        return v[amount];
    }
};