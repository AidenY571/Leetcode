class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) 
    {
        unordered_map<char,int>m;
        
        int start = 0, len = 0;
        
        for(int i = 0; i < s.size(); ++i)
        {
            m[s[i]]++;
            
            while(m.size() > 2)
            {
                m[s[start]]--;
                if(!m[s[start]]) m.erase(s[start]);
                start++;
            }
            
            len = max(len,i - start + 1);
        }
        
        return len;
    }
};