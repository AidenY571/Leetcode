class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int res = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            if(!i) res = nums[0];

            nums[i] = max(nums[i-1]+nums[i],nums[i]);

            res = max(nums[i],res);
        }

        return res;
    }
};