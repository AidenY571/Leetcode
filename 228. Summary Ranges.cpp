class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        vector<string> res;

        for (int i = 0; i < nums.size(); ++i)
        {
            string s = to_string(nums[i]);
            int j = i+1;
            for (; j < nums.size(); ++j)
            {
                if(nums[j] != nums[j-1]+1)break;
            }
            if(j > i+1)
            {
                s += "->"+to_string(nums[j-1]);
                i = j-1;
            }
            res.push_back(s);
        }
        return res;
    }
};