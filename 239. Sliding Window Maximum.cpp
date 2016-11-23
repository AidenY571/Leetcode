class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {        
        vector<int> windows;
        
        deque<int> dq;

        for (int i = 0; i < nums.size(); ++i)
        {
            
            if(i==0) dq.push_back(i);
        
            else
            {
                while(!dq.empty()&&(nums[dq.front()]<=nums[i] || dq.front()<= i-k))
                {
                    dq.pop_front();
                }

                while(!dq.empty()&&nums[dq.back()]<=nums[i])
                {
                    dq.pop_back();
                }

                dq.push_back(i);
            }

            if(i >= k-1)windows.push_back(nums[dq.front()]);
        }

        return windows;
    }
};