class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        if(matrix.empty()) return false;
        
        int row = matrix.size(), col = matrix[0].size();
        
        int l = 0, r = row*col-1;

        while(l <= r)
        {
            int mid = l + (r-l)/2, tmp = matrix[mid/col][mid%col];

            if (tmp == target) return true;
            
            else if(tmp < target) l = mid+1;
            
            else r = mid-1;
        }
        
        return false;
    }
};