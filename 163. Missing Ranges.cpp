class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) 
    {
        vector<string>res;
        
        int start=lower, end=lower;
        
        for(int n:nums)
        {
            if(n==start)start=lower=n+1;
            
            else end=n-1;
            
            if(start<n)
                res.push_back(to_string(start)+(start==end?"":"->"+to_string(end)) );
            
            start=n+1;
        }
        
        if(start<=upper)res.push_back(to_string(start)+(start==upper?"":"->"+to_string(upper)));
        
        return res;
    }
};