class Solution {
public:
    bool canWin(string &s) 
    {
        if(s.empty()) return false;
        
        for(int i = 0; i < s.size()-1; ++i)
        {
            if (s[i] == '+' && s[i+1] == '+')
            {
                s[i] ='-'; s[i+1] = '-';
                
                bool t = canWin(s);
                
                s[i] ='+'; s[i+1] ='+';
                
                if(!t) return true;
            }
        }

        return false;
    }
};