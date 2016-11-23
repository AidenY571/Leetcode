class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> res;
        
        if(matrix.empty()) return res;
            
        int len1 = matrix.size(), len2 = matrix[0].size();
        
        int len = min(len1/2 + len1%2,len2%2 + len2/2);
        
        for (int i = 0; i < len; ++i)
        {
            for (int j = i; j < len2-i; ++j)
            {
                res.push_back(matrix[i][j]);
            }
            
            for (int j = i+1; j < len1-i; ++j)
            {
                res.push_back(matrix[j][len2-1-i]);
            }
            
            if(len1-i-1 == i || len2-i-1 == i) continue;
            
            for (int j = len2-i-2; j >= i; --j)
            {
                res.push_back(matrix[len1-i-1][j]);
            }
            
            for (int j = len1-i-2; j > i; --j)
            {
                res.push_back(matrix[j][i]);
            }
        }
        return res;
    }
};