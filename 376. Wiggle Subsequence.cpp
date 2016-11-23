//DP
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) 
    {
        if(nums.empty()) return 0;

        vector<int> f(size, 1);

        vector<int> d(size, 1);

        for(int i=1; i<nums.size(); ++i)
        {
            for(int j=0; j<i; ++j)
            {
                if(nums[j]<nums[i]) f[i]=max(f[i], d[j]+1);
                
                else if(nums[j]>nums[i]) d[i]=max(d[i], f[j]+1);
            }
        }
        return max(d.back(), f.back());
    }
};

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) 
    {
        if(nums.empty())return 0;
        int a = 1,b=1;

        for (int i = 1; i < nums.size(); ++i)
        {
            if(nums[i]>nums[i-1]) a = b+1;
            else if(nums[i]<nums[i-1]) b = a+1;
        }

        return max(a,b);
    }
}; 