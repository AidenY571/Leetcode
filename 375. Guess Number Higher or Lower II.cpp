class Solution {
public:
    int getMoneyAmount(int n) 
    {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        
        for (int i = 2; i <= n; ++i)
        {
            for (int j = i-1; j >= 1; --j)
            {
                int tmp = INT_MAX;

                for (int k = j ; k <= i; ++k)
                {
                    tmp = min(tmp,k + max(dp[j][k-1],dp[k+1][i]));
                }
                
                dp[j][i] = tmp;

            }
        }
        return dp[2][1];
    }

};