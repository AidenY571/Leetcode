class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) 
    {
        v = matrix;
        row = matrix.size();
        if(!matrix.empty())col = matrix[0].size();
        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                if(i > 0) v[i][j] += v[i-1][j];
                if(j > 0) v[i][j] += v[i][j-1];
                if(i > 0 && j > 0) v[i][j] -= v[i-1][j-1];
                
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        int sum = v[row2][col2];
        if(row1 > 0) sum -= v[row1-1][col2];
        if(col1 > 0) sum -= v[row2][col1-1];
        if(row1 > 0 && col1 > 0) sum += v[row1-1][col1-1];
        return sum;
    }
private:
    vector<vector<int>> v;
    int row=0, col=0;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);