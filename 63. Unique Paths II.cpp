class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int l1 = obstacleGrid.size()-1, l2 = obstacleGrid[0].size()-1;

        for (int i = 0; i <= l1; ++i)
        {
            for (int j = 0; j <= l2; ++j)
            {
                if(obstacleGrid[i][j] == 1) continue;
                
                if(!i && !j) obstacleGrid[i][j] = -1;
                else
                    if (i && obstacleGrid[i-1][j] !=1) obstacleGrid[i][j] += obstacleGrid[i-1][j];
                    if (j && obstacleGrid[i][j-1] !=1) obstacleGrid[i][j] += obstacleGrid[i][j-1];
            }
        }
        
        return -obstacleGrid[l1][l2];
    }
};

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& o) 
    {
        if(o.empty()) return 0;

        vector<int> v = o[0];
        
        v[0] = v[0]^1;
        for (int i = 1; i < v.size(); ++i)
        {
            if(v[i])v[i] = 0;
            else v[i] = v[i-1];
        }

        for (int i = 1; i < o.size(); ++i)
        {
            if(o[i][0]) v[0] = 0;
            for (int j = 1; j < o[0].size(); ++j)
            {
                if(o[i][j]) v[j] = 0;
                else v[j] += v[j-1];
            }
        }
        return v.back();
    }
};