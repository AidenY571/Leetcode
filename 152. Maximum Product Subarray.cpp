class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int neg = 1, pos = 1, res = INT_MIN;

        for (int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] < 0) swap(pos, neg);

            pos = max(pos*nums[i],nums[i]);

            neg = min(neg*nums[i],nums[i]);

            res = max(res,pos);
        }

        return res;
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int front = 1, back = 1, res = INT_MIN, len = nums.size();

        for (int i = 0; i < len; ++i)
        {
            front *= nums[i];
            back *= nums[len-1-i];
            res = max(front,max(back,res));
            if(!front) front = 1;
            if(!back) back = 1;
        }

        return res;
    }
};