class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        if(matrix.empty()) return false;

        int row = matrix.size(), col = matrix[0].size();
        int r_index = 0, c_index = col-1;

        while(r_index < row && c_index >= 0)
        {
            int v = matrix[r_index][c_index];

            if(v == target) return true;

            else if(v > target) --c_index;

            else ++r_index;
        }
        return false;
    }
};