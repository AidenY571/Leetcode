class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) 
    {
        vector<vector<int>> res;
        int len = num.size();
        sort(num.begin(),num.end());

        for (int i = 0; i < len-2; ++i)
        {
            if(num[i]+num[i+1]+num[i+2] > 0) break;

            if(num[i]+num[len-2]+num[len-1] < 0 ) continue;
            
            if(i && num[i] == num[i-1]) continue;
            
            int l = i+1, r = len-1;

            while(l < r)
            {
                if (num[i]+num[l]+num[r] == 0)
                {
                    res.push_back({num[i],num[l],num[r]});
                    ++l;--r;
                    while(l < r && num[r]==num[r+1])--r;
                    while(l < r && num[l]==num[l-1])++l;
                }
                else if(num[i]+num[l]+num[r] > 0) --r;

                else ++l;
            }
        }
        return res;
    }
};