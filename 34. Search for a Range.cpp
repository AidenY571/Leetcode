class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int l = 0, r = nums.size()-1;

        vector<int> res(2,-1);

        while(l <= r)
        {
            int mid = l + (r-l)/2;

            if(nums[mid] > target) r = mid-1;

            else
                l = mid+1;
        }
        
        if(r < 0 || nums[r] != target) return res;

        res[1] = r; l = 0;

        while(l <= r)
        {
            int mid = l + (r-l)/2;

            if(nums[mid] >= target) r = mid-1;

            else
                l = mid+1;
        }

        res[0] = l;

        return res;
    }
};

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int l = 0, r = nums.size()-1;

        vector<int> res(2,-1);

        // Search for the left one
        while (l < r)
        {
            int mid = l + (r - l)/2;
            if (nums[mid] < target) l = mid + 1;
            else r = mid;
        }

        if (nums[l] != target) return res;

        res[0] = l;
        
        // Search for the right one
        r = nums.size()-1; 

        while (l < r)
        {
            int mid = l + (r - l)/2 + 1; // Make mid biased to the right

            if (nums[mid] > target) r = mid - 1; 

            else l = mid;               // So that this won't make the search range stuck.
        }

        res[1] = r;
        
        return res; 
    }
};