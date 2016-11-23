class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) 
    {
        int res = 0, sum=0;

        unordered_map<int,int> m;

        for(int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            
            if(!m.count(sum))m[sum] = i;
            
            if(sum == k) res = max(res,i+1);

            else if (m.count(sum-k))
            {
                res = max(res,i-m[sum-k]);
            }
        }
        return res;
    }
};