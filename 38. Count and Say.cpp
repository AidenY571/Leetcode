class Solution {
public:
    string countAndSay(int n) 
    {
        string s = "1";

        for (int i = 1; i < n; ++i)
        {
            string tmp;
            int count = 0;
            char sign = '+';
            for (int j = 0; j < s.size(); ++j)
            {
                if(s[j]!=sign)
                {
                    if(count)tmp += to_string(count)+sign;
                    sign = s[j];
                    count = 1;
                }
                else ++count;
                
                if(j == s.size()-1)
                {
                    tmp += to_string(count)+sign;
                }
            }
            s = tmp;
        }
        return s;
    }
};