class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        int v[26] = {0};
        
        if(s.size()!=t.size()) return false;
        
        for(char i : s) v[i-'a']++;
        
        for(char i : t) if(--v[i-'a'] < 0) return false;
        
        return true;
    }
};