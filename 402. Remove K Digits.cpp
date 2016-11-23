class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        int len = num.size();
        
        if(len <= k) return "0";

        while(k)
        {
            for (int i = 0; i < len; ++i)
            {
                if(i == len - 1 ||num[i] > num[i+1])
                {
                    num.erase(num.begin()+i);
                    break;
                }
            }

            k--;len--;
        }

        for (int i = 0; i <= len; ++i)
        {
            if(num[i] > '0')
            {
                num = num.substr(i);
                break;
            }
        }
        return num;
    }
};