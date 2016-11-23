class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        if(s.empty()) return true;
        
        unordered_map<char,char> m;
        unordered_map<char,char> n;
        for (int i = 0; i < s.size(); ++i)
        {
            if(m.count(s[i]) && m[s[i]]!=t[i])
                return false;
            m[s[i]] = t[i];

            if(n.count(t[i]) && n[t[i]]!=s[i])
                return false;
            n[t[i]] = s[i];
        }
        return true;
    }
};

class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        if(s.empty()) return true;
        vector<char> a(150,'+');
        vector<char> b(150,'+');
        for (int i = 0; i < s.size(); ++i)
        {
            if(a[s[i]] != '+' && a[s[i]] != t[i])
                return false;
            a[s[i]] = t[i];

            if(b[t[i]] != '+' && b[t[i]] != s[i])
                return false;
            b[t[i]] = s[i];
        }
        return true;
    }
};