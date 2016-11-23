class Solution {
public:
    bool increasingTriplet(vector<int>& nums) 
    {
        int first = INT_MAX,second = INT_MAX;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > second) return true;
            
            if (nums[i] <= first) first = nums[i];
            
            else 
                second = nums[i];
        }
        return false;
    }
};