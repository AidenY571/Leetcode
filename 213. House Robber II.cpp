class Solution {
public:
    int rob(vector<int>& nums)  
    {
        if (nums.size() == 0) return 0;
        
        if (nums.size() == 1) return nums[0];
        
        int pre = 0, cur = nums[0];

        for (int i = 1; i < nums.size()-1; ++i)
        {
            int tmp = pre + nums[i];

            pre = cur;

            cur = max(tmp,cur);
        }

        int pre1 = 0, cur1 = nums[1];

        for (int i = 2; i < nums.size(); ++i)
        {
            int tmp = pre1 + nums[i];

            pre1 = cur1;

            cur1 = max(tmp,cur1);
        }

        return max(cur,cur1);
    }
};