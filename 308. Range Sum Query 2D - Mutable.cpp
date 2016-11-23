class NumMatrix {
private:
    vector<vector<int>> bit;
    vector<vector<int>> num;
    int row = 0, col = 0;
public:
    NumMatrix(vector<vector<int>> &matrix) 
    {
        row = matrix.size();
        if(!matrix.empty()) col = matrix[0].size();
        num = vector<vector<int>>(row,vector<int>(col,0));
        bit = vector<vector<int>>(row+1,vector<int>(col+1,0));
        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                update(i,j,matrix[i][j]);
            }
        }
    }

    void update(int r, int c, int val) 
    {
        int diff = val - num[r][c];
        num[r][c] = val;
        ++r;++c;
        while(r <= row)
        {
            int tmp = c;
            while(tmp <= col)
            {
                bit[r][tmp] += diff;
                tmp += (tmp & (-tmp));
            }
            
            r += (r & (-r));
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        if(!row || !col) return 0;
        return sum(row2, col2) - sum(row1-1,col2) - sum(row2,col1-1) + sum(row1-1,col1-1);
    }
    
    int sum(int r, int c)
    {
        int res = 0;
        ++r;++c;
        while(r > 0)
        {
            int tmp = c;
            while(tmp > 0)
            {
                res += bit[r][tmp];
                tmp -= (tmp & (-tmp));
            }
            
            r -= (r & (-r));
        }
        return res;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);