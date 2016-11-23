class Solution {
private:
    vector<int> v;
    int len = 0;
public:
    Solution(vector<int> nums) {
        v = nums;
        len = nums.size();
    }
    
    int pick(int target) 
    {
        int count = 1, index = -1;
        
        for(int i = 0; i < len; ++i)
        {
            if(v[i] == target)
            {
                if(!(rand()%count))
                {
                    index = i;
                }
                
                count++;
            }
        }
        
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */