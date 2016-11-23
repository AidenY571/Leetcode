class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) 
    {
        int row = grid.size(), col = row ? grid[0].size() : 0;
        
        vector<vector<int>> v(row,vector<int>(col
        ,0));
        int res = 0;

        for (int i = 0; i < row; ++i)
        {
            int tmp = 0, index = 0;
            for (int j = 0; j < col; ++j)
            {
                if(grid[i][j] =='E') ++tmp;
                
                if(grid[i][j] == 'W' || j == col-1)
                {
                    for (int k = index; k <= j; ++k)
                    {
                        if(grid[i][k] =='W') continue;
                        v[i][k] = tmp;
                    }

                    index = j+1;
                    tmp = 0;
                }
            }
        }

        for (int i = 0; i < col; ++i)
        {
            int tmp = 0, index = 0;
            for (int j = 0; j < row; ++j)
            {
                if(grid[j][i] =='E') ++tmp;

                if(grid[j][i] == 'W' || j == row-1)
                {
                    for (int k = index; k <= j; ++k)
                    {
                        if(grid[k][i] == 'E' || grid[k][i] == 'W') continue;
                        v[k][i] += tmp;
                        res = max(res,v[k][i]);
                    }

                    index = j+1;
                    tmp = 0;
                }
            }
        }

        return res;
    }
};