class Solution {
public:
    int findPeakElement(vector<int>& num) 
    {
        int low = 0, high = num.size()-1;
        
        while(low < high)
        {
            int mid = low + (high-low)/2;
            
            if(num[mid] < num[mid+1]) low = mid+1;
            
            else high = mid;
        }
        return low;
    }
};

class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        int a = 0, b = nums.size()-1, mid = 0;
        int left, right;

        while(a <= b)
        {
            int mid = (a+b)/2;

            left= (mid == 0)? INT_MIN: nums[mid-1];

            right = (mid == nums.size()-1)? INT_MIN: nums[mid+1];

            if (nums[mid]<left) b = mid-1;

            else if (nums[mid]<right) a = mid+1;

            else
                return mid;
        }

        return mid;
    }
};
