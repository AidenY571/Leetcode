class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        int dif = 0;

        for (int i:nums) dif ^= i;
        
        dif = dif & (~(dif-1));

        int first = 0, second = 0;

        for (int i:nums)
        {
            if(dif & i) first ^= i;
            else second ^= i;
        }

        return {first,second};
    }
};