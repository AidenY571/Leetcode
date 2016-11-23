class Solution {
public:
    char findTheDifference(string s, string t) {
        char r = 0;
        for(char c:s) r ^=c;
        for(char c:t) r ^=c;
        return r;
    }
};

class Solution {
public:
    char findTheDifference(string s, string t) 
    {
        int alph[26] = {0};

        for (int i = 0; i < t.size(); ++i)
        {
            ++alph[t[i] - 'a'];
            if(i < s.size()) --alph[s[i] - 'a'];
        }

        for (int i = 0; i < 26; ++i)
        {
            if(alph[i]) return 'a'+i;
        }

        return ' ';
    }
};