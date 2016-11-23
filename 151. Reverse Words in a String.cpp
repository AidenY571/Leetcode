//O(n) Space
class Solution {
public:
    void reverseWords(string &s) 
    {
        int pos = 0;

        string res;

        for (int i = 0; i < s.size(); ++i)
        {
            if(s[i] == ' ')
            {
                if (pos != i) res = s.substr(pos,i-pos)+" "+res;
                pos = i+1;
            }
            else
                if(i==s.size()-1)res = s.substr(pos,i-pos+1)+" "+res;
        }
        
        if(res.back() == ' ')res.pop_back();
        
        s = res;
    }
};

//O(1) Space
class Solution {
public:
    void reverseWords(string &s) 
    {
        reverse(s.begin(),s.end());

        int pos = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            if(s[i] == ' ')
            {
                if(pos != i) 
                {
                    reverse(s.begin()+pos,s.begin()+i);
                    pos = i+1;
                }
                else
                    s.erase(s.begin()+ (i--));
            }
            else
                if(i == s.size()-1) reverse(s.begin()+pos,s.end());
        }
        
        if(s.back()==' ')s.pop_back();
    }
};