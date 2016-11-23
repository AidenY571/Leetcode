//array
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int m[200]={0}, res = 0, begin = 0;
        
        for (int i = 0; i < s.size(); ++i)
        {
            if(m[s[i]] == 0) m[s[i]] = i+1;

            else
            {
                if(m[s[i]]-1 >= begin) begin = m[s[i]];
                
                m[s[i]] = i+1;
            }
            
            res = max(res,i - begin + 1);

        }
        return res;
    }
};

//hash table
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int res = 0,begin = 0;

        unordered_map<char,int> m;
        
        for (int i = 0; i < s.size(); ++i)
        {
            if(m.find(s[i]) == m.end()) m[s[i]] = i;

            else
            {
                if(m[s[i]] >= begin) begin = m[s[i]]+1;
                
                m[s[i]] = i;
            }
            
            res = max(res,i - begin + 1);

        }

        return res;
    }
};