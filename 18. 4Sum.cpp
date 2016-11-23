class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> res;

        if (nums.size()< 4) return res;
        
        int len = nums.size(); 
        
        sort(nums.begin(),nums.end());

        for (int i = 0; i < len - 3; ++i)
        {
            if(i && nums[i]==nums[i-1]) continue;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            if(nums[i]+nums[len-3]+nums[len-2]+nums[len-1]<target) continue;
            for (int j = i+1; j < len - 2; ++j)
            {
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if(nums[i]+nums[len-1]+nums[len-2]+nums[j]<target) continue;
                if (j>i+1 && nums[j] == nums[j-1]) continue;
                
                int l = j + 1, r = len - 1, tmp = nums[i] + nums[j];

                while(l < r)
                {
                    if (tmp + nums[l] + nums[r] == target)
                    {
                        res.push_back({nums[i],nums[j],nums[l++],nums[r--]});
                        
                       while(l<r&&nums[l]==nums[l-1])l++;
                       while(l<r&&nums[r]==nums[r+1])r--;
                        
                    }
                    else if (tmp + nums[l] + nums[r] > target) --r;
                    else
                        ++l;
                }
            }
        }
        
        return res;
    }
};