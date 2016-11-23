// Two Pointers
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) 
    {
        int len = INT_MAX, index = 0, sum = 0;
        
        for(int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
             
            while(sum - nums[index] >= s )
            {
                sum -= nums[index++];
            }
            
            if(sum >= s) len = min(len,i-index+1);
            
        }
        return len == INT_MAX? 0:len;
    }
};


//Binary Search
class Solution {
public:
    int binary_search(vector<int>&sum, int left, int target)
    {
        int right = sum.size()-1, mid;

        while(left<=right)
        {
            mid = (left+right)>>1;
            if(sum[mid]>=target) right = mid-1;
            else left = mid+1;
        }

        return (left<sum.size()?left:-1);
    }

    int minSubArrayLen(int s, vector<int>& nums) 
    {
        int len = nums.size();
        vector<int> sum(len+1,0);
        int i, start = 0, end;
        int res = len+1;
     
        if(len>0)
        {
            for(i=1;i<=len;i++) sum[i] =sum[i-1] + nums[i-1];
                
            while(start<len && (end = binary_search(sum, start+1, s+sum[start]))>=0 )
            {
                res = min(res, end-start);
                start++;
            }
        }
        return res>len?0:res;
    }
};