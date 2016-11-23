class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int res = 0;
        
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j]=='1')
                {
                    res++;
                    check(grid,i,j);
                }
            }
        }
        return res;
    }

    void check(vector<vector<char>>& grid, int x ,int y)
    {
        if(x == grid.size() || y==grid[0].size()||
           x < 0 || y < 0 || grid[x][y]=='0') return;
        grid[x][y] = '0';
        check(grid,x+1,y);
        check(grid,x,y+1);
        check(grid,x-1,y);
        check(grid,x,y-1);
    }
};


//Union find
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        if(grid.empty()) return 0;

        int row = grid.size(), col = grid[0].size(), num = 0;

        int moves[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

        root = vector<int>(row*col,-1);

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if(grid[i][j]=='1')
                {
                    int cur_pos = col*i + j;

                    ++num;
                    
                    root[cur_pos] = cur_pos;

                    for (auto move : moves)
                    {
                        int n_row = i+move[0], n_col = j+move[1], index = n_row*col + n_col;
                
                        if (n_row < 0 || n_row >= row || n_col < 0 || n_col >= col || root[index] == -1) continue;
                        
                        int tmp_root = find_root(index);

                        if(cur_pos != tmp_root)
                        {
                            root[tmp_root] = cur_pos;
                            --num;
                        }
                    
                    }
                }
            }
        }

        return num;
    }
private:
    vector<int> root;
    int find_root(int id)
    {
        while(id != root[id])
        {
            root[id] = root[root[id]];
            id = root[id];
        }
        return id;
    }
};