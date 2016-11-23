class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) 
    {
        if(nums.empty()) return {};

        int len = nums.size();

        vector<int> res(len,0);

        if(a != 0)
        {
            double mid= -(double)b/(2*(double)a);
            
            int l = 0, r = len - 1, m = len-1, n = 0;
        
            while(l <= r)
            {
                int tmp = (abs(mid - (double)nums[l]) >= abs((double)nums[r]-mid) ? nums[l++]:nums[r--]);

                if(a > 0) res[m--] = (a*tmp*tmp+b*tmp+c);
                
                else
                    res[n++] = (a*tmp*tmp+b*tmp+c);
            }
        }
        else
        {
            for(int i = 0; i < len; ++i) 
            {
                if(b >= 0) res[i] = b*nums[i] + c;
                else
                    res[len-1-i] = b*nums[i] + c;
            }
        }
        
        return res;
    }
};