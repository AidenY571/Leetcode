class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int l = 0, r = numbers.size()-1;

        while(l < r)
        {
            if(numbers[l]+numbers[r] == target) return {l+1,r+1};

            else if(numbers[l]+numbers[r] > target) --r;

            else ++l;
        }
        return {};
    }
};

//Binary Search
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int len = nums.size();

        for (int i = 0; i < len; ++i)
        {
            int l = i+1, r = len-1;
            
            while(l <= r)
            {
                int tmp = l + (r-l)/2;

                if (nums[i] + nums[tmp] == target) return {i+1,tmp+1};
                
                else if(nums[i] + nums[tmp] > target) r = tmp-1;

                else l = tmp + 1;
            }
        }
        return {};
    }
};