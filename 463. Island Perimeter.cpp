class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        int num = 0;
        
        for(int row = 0; row < grid.size(); ++row)
        {
            for(int col = 0; col < grid[0].size(); ++col)
            {
                if(!grid[row][col]) continue;
                if(!row || !grid[row-1][col]) ++num;
                if(!col || !grid[row][col-1]) ++num;
                if(row == grid.size()-1 || !grid[row+1][col]) ++num;
                if(col == grid[0].size()-1 || !grid[row][col+1]) ++num;
            }
        }
        
        return num;
    }
};