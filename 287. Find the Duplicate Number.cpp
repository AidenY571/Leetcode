class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        if(nums.empty()) return 0;
        
        int l = 0, r = nums.size()-1;

        sort(nums.begin(),nums.end());
        
        while(l < r)
        {
            int mid = l+(r-l)/2;

            if (nums[mid] > mid)
            {
                l = mid+1;
            }
            else
                r = mid;
        }

        return nums[l];
    }
};

int findDuplicate3(vector<int>& nums)
{
    if (nums.size() > 1)
    {
        int slow = nums[0];
        int fast = nums[nums[0]];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        fast = 0;
        while (fast != slow)
        {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
    return -1;
}