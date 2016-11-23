class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int l = 0, r = nums.size()-1, mid = 0;
        
        while(l < r)
        {
            if(nums[l] < nums[r]) return nums[l];
            
            mid = l + (r-l)/2;
            
            if(nums[mid] > nums[r]) l = mid + 1;
            
            else if(nums[mid] > nums[l])r = mid-1;
            
            else {++l;--r;}
        }
        
        return nums[l];
    }
};