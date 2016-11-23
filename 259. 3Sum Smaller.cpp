class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end());

        int len = nums.size(), res = 0;

        for (int i = 0; i < len-2; ++i)
        {
            int l = i+1, r = len-1;

            while(l < r)
            {
                if (nums[i] + nums[l] + nums[r] < target)
                {
                    res += r - l;
                    l++;
                }
                else
                    r--;
            }
        }

        return res;
    }
};