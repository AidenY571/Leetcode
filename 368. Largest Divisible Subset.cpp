class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        int len = nums.size();
        
        if(!len) return {};
        
        sort(nums.begin(),nums.end());
        
        vector<int> res(len,1);
        
        vector<int> index(len,0);
        
        vector<int> result;
        
        int tmp = 1,pos=0;
        
        for (int i = 1; i < len; ++i)
        {
            index[i] = i;
            
            for (int j = i-1; j >=0; --j)
            {
                if (nums[i] % nums[j] == 0 && res[i] <= res[j])
                {
                    res[i] = res[j]+1;
                    index[i] = j;
                }
            }

            if(res[i]>tmp)
            {
                tmp = res[i];
                pos = i;
            }
        }

        while(tmp--)
        {
            result.push_back(nums[pos]);
            pos = index[pos];
        }

        return result;
    }
};