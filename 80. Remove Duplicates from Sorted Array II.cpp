class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int pos = 2, len = nums.size();
        
        if(len < 3) return len;
        
        for(int i = 2; i < len; ++i)
        {
            if(nums[i] == nums[pos-2]) continue;
            
            nums[pos++] = nums[i];
        }
        
        return pos;
    }
};