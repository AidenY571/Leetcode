class Solution {
public:
    int numDecodings(string s) 
    {
        if(s.empty() || s[0] == '0') return 0;
        
        int len = s.size(), num[len] = {0};
        
        num[0] = 1;
        
        for(int i = 1; i < len; ++i)
        {
            if(s[i] != '0') num[i] += num[i-1];
            
            if(s[i-1] == '1' || (s[i-1] == '2' && s[i] < '7'))
            {
                if(i == 1) ++num[i];
                else num[i] += num[i-2];
            }
        }
        
        return num[len-1];
    }
};