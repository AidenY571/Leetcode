class Solution {
public:
    int countNumbersWithUniqueDigits(int n) 
    {
        int res = 0;

        for (int i = 1; i <= n; ++i)
        {
            int tmp = 1;

            for (int j = 1; j <= i; ++j)
            {
                if(j < 3) tmp *= 9;
                else
                    tmp *= 9-j+2;
            }

            res += tmp;
        }
        
        return res+1;
    }
};