class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        vector<int> dp;
        
        for (int i : nums) 
        {
            int index = binary_search(dp, i);

            if (index == dp.size()) dp.push_back(i);

            else 
                dp[index] = i;
        }

        return dp.size();
    }

    int binary_search(vector<int>& vec, int target) 
    {
        int low = 0, high = vec.size() - 1;

        while (low < high) 
        {
            int mid = (low + high) / 2;
            if (target > vec[mid]) low = mid + 1;
            else 
                high = mid;
        }
        
        if (low == vec.size() - 1 && vec[low] < target) low++;

        return low;
    }

};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        if(nums.empty()) return 0;
        
        int len = nums.size(), end = 0;
        
        vector<int> v(len,INT_MIN);
        
        v[0] = nums[0];
        
        for(int i=1; i < len; ++i)
        {
            if(nums[i] <= v[0]) v[0] = nums[i];
            
            else if(nums[i] > v[end]) v[++end] = nums[i];
            
            else
            {
                int pos = check(v,nums[i],end);
                
                v[pos] = nums[i];
            }
            
        }
        
        return end+1;
    }
    
    int check(vector<int> &v, int target, int len)
    {
        int l = 0, r = len;
        
        while(r > l)
        {
            int mid = l + (r-l)/2;
            if(v[mid] == target) return mid;
            else if(v[mid] > target) r = mid;
            else l = mid+1;
        }
        
        return r;
    }
};

class Solution {
public:
     int lengthOfLIS(vector<int>& nums) 
     {
        int maxLen = 0;

        auto begin = nums.begin();

        for (int i:nums)
        {
            auto ret = lower_bound(begin, begin + maxLen, i);
            
            if (ret == begin + maxLen)
                *(begin + maxLen++) = i;
            else if (i < *ret)
                *ret = i;
        }
        
        return maxLen;
    }
};