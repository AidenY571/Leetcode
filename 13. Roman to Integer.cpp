class Solution {
public:
    int romanToInt(string s) 
    {
        int res = check(s.back()),len = s.size(), pre = res;

        for (int i = len - 2; i >= 0; --i)
        {
            int tmp = check(s[i]);
            
            if(tmp < pre) res -= tmp;
            else
                res += tmp;
                
            pre = tmp;
        }

        return res;
    }

    int check(char c)
    {
        switch(c)
        {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        
        return 0;
    }
};