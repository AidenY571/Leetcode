//O(m+n) space
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        if(matrix.empty()) return;
        
        int row[matrix.size()]={0}, col[matrix[0].size()]={0};

        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
               if (matrix[i][j] == 0) row[i] = col[j] = 1;
            }   
        }

        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                if(row[i]||col[j]) matrix[i][j] = 0;
            }
        }

        return;
    }
};
// O(1) Space
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        if(matrix.empty()) return;

        int sign = 0, row = matrix.size(), col = matrix[0].size();

        for (int i = 0; i < row; ++i)
        {
            if(matrix[i][0]==0) sign = 1;
            
            for (int j = 1; j < col; ++j)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = row-1; i >= 0; --i)
        {
            for (int j = col-1; j >= 1; --j)
            {
                if(matrix[0][j]==0 || matrix[i][0]==0)
                    matrix[i][j] = 0;
            }
            if(sign) matrix[i][0] = 0;
        }

        return;
    }
};