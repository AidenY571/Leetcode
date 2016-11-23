class Solution {
public:
    int calculate(string s) 
    {
        int total = 0, temp = 0;
        
        char sign = '+';
        
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i]==' ') continue;

            if(isdigit(s[i]))
            {
                int tmp = s[i] -'0';
                
                while(i+1 < s.size() && isdigit(s[i+1]))
                {
                    tmp = tmp*10 + s[++i]-'0';
                }

                switch(sign)
                {
                    case '+': temp += tmp;break;
                    case '-': temp -= tmp;break;
                    case '*': temp *= tmp;break;
                    case '/': temp /= tmp;break;
                }

            }
            else
            {
                if (s[i] == '+' || s[i] =='-')
                {
                    total += temp;
                    temp = 0;
                }
                
                sign = s[i];
            }
            
        }
        
        return total+temp;
    }
};