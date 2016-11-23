class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        int len = nums.size();
        
        for (int i = 0; i < len; ++i)
        {
            if(nums[i] != i+1 && nums[i] <= len && nums[i] > 0 && nums[nums[i]-1] != nums[i])
            {
                swap(nums[i],nums[nums[i]-1]);
                i--;
            }
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] != i+1) return i+1;
        }
        
        return len+1;
    }
};