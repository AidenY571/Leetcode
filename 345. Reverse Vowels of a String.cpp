class Solution {
public:
    string reverseVowels(string s) 
    {
        int l = 0, r = s.size()-1;
        
        while(l < r)
        {
            while(l < r && !vowels(s[l])) ++l;
            while(l < r && !vowels(s[r])) --r;
            if(l < r)swap(s[l++],s[r--]);
        }
        return s;
    }

    bool vowels(char c)
    {
        c = tolower(c);
        if(c == 'a'|| c == 'e'||c == 'i'||c == 'o'||c == 'u')
            return true;
        return false;
    }
};