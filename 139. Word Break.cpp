class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) 
    {
        bool res = false;
        
        int len = s.size(), a[len+1]={0}, lmax = 0;
        
        for(auto str:wordDict) lmax = max(lmax,(int)str.size());
        
        a[0]=1;
        
        for (int i = 0; i < len; ++i)
        {
            for (int j = i; i - j + 1 <= lmax && j >= 0; --j)
            {
                if (wordDict.count(s.substr(j,i-j+1)) && a[j])
                {
                    a[i+1] = 1;
                    break;
                }
            }
        }
        return a[len];
    }
};