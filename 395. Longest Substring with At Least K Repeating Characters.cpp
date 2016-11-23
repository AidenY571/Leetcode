class Solution {
public:
    int longestSubstring(string s, int k) 
    {
        if(s.size() < k) return 0;
        
        int c[200] = {0};
        
        for(char i : s) ++c[i];
        
        int len = s.size();
        
        for(int i = 0; i < len; ++i)
        {
            if(c[s[i]] && c[s[i]] < k)
            {
                string l = s.substr(0, i);
                string r = s.substr(i+1);
                return max(longestSubstring(l,k),longestSubstring(r,k));
            }
        }
        
        return len;
    }
};