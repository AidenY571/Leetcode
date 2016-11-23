class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int len = matrix.size()-1;
        
        for (int i = 0; i <= len/2; ++i)
        {
            for (int j = i; j < len-i; ++j)
            {
                swap(matrix[i][j], matrix[j][len-i]);
                swap(matrix[i][j], matrix[len-i][len-j]);
                swap(matrix[i][j], matrix[len-j][i]);
            }
        }
    }
};