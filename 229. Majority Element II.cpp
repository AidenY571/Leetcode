class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int a[2] = {0}, b[2] = {0}, len = nums.size();
        
        vector<int> res;

        for (int i = 0; i < len; ++i)
        {
            if(a[0] == nums[i]) {++a[1];continue;}

            if(b[0] == nums[i]) {++b[1];continue;}

            if(!a[1]) {a[0] = nums[i];++a[1];continue;}

            if(!b[1]) {b[0] = nums[i];++b[1];continue;}

            --a[1]; --b[1];
        }

        a[1] = 0; b[1] = 0;

        for (int i : nums)
        {
            if(i == a[0]) {a[1]++;continue;}
            if(i == b[0]) b[1]++;
        }

        if(a[1] > len/3) res.push_back(a[0]);

        if(b[1] > len/3) res.push_back(b[0]);

        return res;
    }
};