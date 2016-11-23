class Solution {
public:
    int myAtoi(string str) 
    {
        long res = 0;
        
        int sign = 1, index = 0;

        while(str[index] == ' ')++index;
        
        if(str[index]=='-' ||str[index]=='+')
        {
            if(str[index++]=='-')sign = -1;
        }
        
        while(str[index]>='0' && str[index]<='9')
        {
            res = res*10 + str[index++]-'0';
            if(res > INT_MAX)
            {
                if(sign > 0) return INT_MAX;
                return INT_MIN;
            }
        }
        
        return res *= sign;
    }
};