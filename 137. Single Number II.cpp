class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        vector<int> bit(32,0);

        for (int i = 0; i < nums.size(); ++i)
        {
            for(int j = 0; j<32; ++j)
            {
                int rotated = nums[i]>>j;
                if(!rotated) break;
                bit[j] += rotated & 1;
            }
        }
         
        int target=0;
        for(int i =0; i<32; ++i)
        {
             target += (bit[i]%3 <<i);
        }

        return target;
    }
};