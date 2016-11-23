//Method 1  Time Complexity O(n), Space Complexity O(n)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); ++i)
        {
        	if (s.find(nums[i]) != s.end()) return true;

        	s.insert(nums[i]);
        	
        }
        return false;
    }
};

//Method 2   Time Complexity O(nlogn), Space Complexity O(1)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        return unique(nums.begin(), nums.end()) != nums.end();
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
     	if(nums.empty()) return false;
     	
     	sort(nums.begin(), nums.end());

     	for (int i = 0; i < nums.size()-1; ++i)
     	{
     	   	 if (nums[i] == nums[i+1])
     	   	 {
     	   	 	return true;
     	   	 }
        }

        return false;

    }
};