class Solution {
public:
    vector<int> diffWaysToCompute(string input) 
    {
        vector<int> res;

        return check(input,res);
    }

    vector<int> check(string s, vector<int> v)
    {
        for (int i = 0; i < s.size(); ++i)
        {
            int tmp = 0;

            if (s[i]<'0' && s[i]>'9') break;

            if (i == s.size() - 1)
            {
                for (int j = 0; j < s.size(); ++j)
                {
                    if (j == 0 && s[j] == '-') continue;
                    tmp = tmp * 10 + (s[j] - '0');
                }
                if (s[0] == '-') tmp *= -1;
                v.push_back(tmp);
                return v;
            }
        }

        

        for (int i = 0; i < s.size(); ++i)
        {   
            int a = 0,b=0,start = i, neg=0;

            if (s[i] == '-') 
            {
                neg = -1;
                i++;
            }
            
            while(s[i]>='0' && s[i]<='9' && i < s.size())
            {
                a = a*10 +s[i] -'0';
                i++;
            }

            if (neg == 1) 
            {
                a = a*(-1);
                neg = 0;
            }
            
            char sign = s[i];

            i++;

            if (s[i] == '-')
            {
                neg = 1;
                i++;
            }

            while(s[i]>='0' && s[i]<='9' && i < s.size())
            {
                b = b*10 +s[i]-'0';
                i++;
            }

            if (neg == 1) 
            {
                b = b*(-1);
                neg = 0;
            }

            if (sign == '+')
            {
                int tmp = a + b
                s = s.substr(0,start)+to_string(tmp)+s.substr(i+1,s.size());
            }
            else if (sign == '-')
            {
                int tmp = a - b;
                s = s.substr(0,start)+to_string(tmp)+s.substr(i+1,s.size());
            }
            else if (sign == '*')
            {
                int tmp = a*b;
                s = s.substr(0,start)+to_string(tmp)+s.substr(i+1,s.size());
            }

            v = check(s,v);
        }

        return v;
    }
};