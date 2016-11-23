class Solution {
public:
    bool isOneEditDistance(string s, string t) 
    {
        int len1 = s.size(), len2 = t.size();

        if(abs(len1-len2)>1 || s == t) return false;

        for (int i = 0; i < len1 && i < len2; ++i)
        {
            if(s[i] != t[i])
            {
                if(s.substr(i+1) == t.substr(i+1)
                   || s.substr(i) == t.substr(i+1)
                   || s.substr(i+1) == t.substr(i)) return true;
                else 
                    return false;
            }
        }

        return true;
    }
};