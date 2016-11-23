class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        if(nums.size() < 3) return 0;
        
        sort(nums.begin(),nums.end());
        
        int res = nums[0]+nums[1]+nums[2];

        for (int i = 0; i < nums.size()-2; ++i)
        {
            if(i && nums[i] == nums[i-1]) continue;
            
            int l = i + 1, r = nums.size()-1;

            while(l < r)
            {
                int tmp = nums[i] + nums[l] + nums[r];
                
                if(abs(tmp-target) < abs(res-target)) res = tmp;
                
                if(tmp > target) --r;
                
                else if(tmp < target) ++l;
                
                else return tmp;
            }
        }
        return res;
    }
};