class Solution {
public:
    bool search(vector<int>& nums, int target) 
    {
        int l = 0, r = nums.size()-1;

        while(l <= r)
        {
            while(l != r && nums[l] == nums[r]) r--;

            int mid = (r+l)/2;

            if (nums[mid] == target) return mid;        
            
            if (nums[mid] >= nums[l])
            {
                if (target < nums[mid] && target >= nums[l]) r = mid - 1;

                else
                    l = mid + 1;
            }
            else
            {
                if (target > nums[mid] && target <= nums[r]) l = mid + 1;
                
                else
                    r = mid - 1;
            }
        }
        
        return -1;        
    }
};