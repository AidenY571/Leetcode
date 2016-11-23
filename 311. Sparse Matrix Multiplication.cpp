class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) 
    {
        int row = A.size(), lenA = A[0].size(), col = B[0].size();
        
        vector<vector<int>> res(A.size(), vector<int>(B[0].size(),0));

        for(int i = 0; i < row; i++)
        {
            for(int k = 0; k < lenA; k++)
            {
                if(A[i][k] != 0)
                {
                    for(int j = 0; j < col; j++)
                    {
                        res[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
        }
        return res;
    }
};