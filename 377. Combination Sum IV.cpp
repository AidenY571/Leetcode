class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end());

        int arr[target+1]={0};

        arr[0] = 1;
        
        for (int i = 1; i <= target; ++i)
        {
            for (int j = 0; j < nums.size(); ++j)
            {
                if (i < nums[j]) break;

                if(i>=nums[j]) arr[i] += arr[i-nums[j]];
            }
            
        }

        return arr[target];
    }
};

