class Solution {
public:
    int jump(vector<int>& nums) 
    {
        if(nums.size()<2) return 0;

        int pos = 0, res = 0, len = nums.size()-1;

        while(pos < len)
        {
            if(pos + nums[pos] >= len) return res+1;
            
            int dis = 0, t_pos = 0;
            
            for (int i = 1; i <= nums[pos]; ++i)
            {
                
                if(!nums[pos+i]) continue;

                if(dis < nums[pos+i] + pos+i)
                {
                    t_pos = pos+i;
                    dis = nums[pos+i] + pos+i;
                }
            }
            pos = t_pos;
            ++res;
        }
        
        return res;
    }
};