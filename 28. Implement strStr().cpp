class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        if(needle.empty())return 0;
        
        int len1 = needle.size(), len2 = haystack.size();
        
        if(haystack.empty() || len1 > len2) return -1;

        for (int i = 0; i <= len2-len1; ++i)
        {
            if(haystack.substr(i,len1) == needle) return i;
        }
        return -1;
    }
};