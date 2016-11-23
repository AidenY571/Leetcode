class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>> res(n,vector<int>(n,0));
        int num = 1;
        for (int i = 0; i < n/2 + n%2; ++i)
        {
            for (int j = i; j < n-i; ++j)
            {
                res[i][j] = num++;
            }
            
            for (int j = i+1; j < n-i; ++j)
            {
                res[j][n-1-i] = num++;
            }
            
            for (int j = n-i-2; j >= i; --j)
            {
                res[n-i-1][j] = num++;
            }
            
            for (int j = n-i-2; j > i; --j)
            {
                res[j][i] = num++;
            }
        }
        return res;
    }
};