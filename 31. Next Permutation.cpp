class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        if(nums.size() < 2)return;
        int len = nums.size();
        
        for (int i = len - 1; i >= 0; --i)
        {
            for (int j = len - 1; j > i; --j)
            {
                if(nums[i] < nums[j])
                {
                    swap(nums[i],nums[j]); 
                    sort(nums.begin()+i+1,nums.end());
                    return;
                }
            }
        }

        reverse(nums.begin(),nums.end());
        return;
    }
};