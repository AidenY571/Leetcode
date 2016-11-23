//Sorting
//Since the majority element appears more than n / 2 times, 
//the n / 2-th element in the sorted nums must be the majority element. 
class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        
        return nums[nums.size()/2];
    }
};

//Moore Voting Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int len = nums.size(), res = 0, n = 0;
        
        for(int i = 0; i < len ; i++)
        {
            if(n==0) {res = nums[i]; n++;}
            else
            {
                if(res == nums[i]) n++;
                else
                    n--;
                if(n > len/2) return res;
            }
        }
        return res;
    }
};

//Hash Table
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts; 
        int n = nums.size();
        for (int i = 0; i < n; i++)
            if (++counts[nums[i]] > n / 2)
                return nums[i];
    }
};

//Randomization
//The code is as follows, randomly pick an element and see if 
//it is the majority one.
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        srand(unsigned(time(NULL)));
        while (true) {
            int idx = rand() % n;
            int candidate = nums[idx];
            int counts = 0; 
            for (int i = 0; i < n; i++)
                if (nums[i] == candidate)
                    counts++; 
            if (counts > n / 2) return candidate;
        }
    }
};

//Divide and Conquer
class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        return majority(nums, 0, nums.size() - 1);
    }

    int majority(vector<int>& nums, int left, int right) 
    {
        if (left == right) return nums[left];
        int mid = left + ((right - left) >> 1);
        int lm = majority(nums, left, mid);
        int rm = majority(nums, mid + 1, right);
        if (lm == rm) return lm;
        return count(nums.begin() + left, nums.begin() + right + 1, lm) > 
               count(nums.begin() + left, nums.begin() + right + 1, rm) ? lm : rm;
    }
}; 

/* Bit Manipulation
Another nice idea! The key lies in how to count the number of 1's 
on a specific bit. Specifically, you need a mask with a 1 on the 
i-the bit and 0 otherwise to get the i-th bit of each element in nums.*/ 

class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int major = 0, n = nums.size();
        for (int i = 0, mask = 1; i < 32; i++, mask <<= 1) 
        {
            int bitCounts = 0;
            for (int j = 0; j < n; j++) 
            {
                if (nums[j] & mask) bitCounts++;

                if (bitCounts > n/2) {major |= mask; break;}
            }
        } 
        return major;
    } 
};