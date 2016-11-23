class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        int res = 0;
        
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                if(matrix[i][j] == '0') continue;
                
                int a = 0, b = 0, c = 0;
                if (i > 0) a = matrix[i-1][j]-'0';
                if (j > 0) b = matrix[i][j-1]-'0';
                if (i > 0 && j > 0) c = matrix[i-1][j-1]-'0';

                matrix[i][j] += min(min(a,b),c);

                res = max(res,matrix[i][j]-'0');
            }
        }
        return res*res;
    }
};