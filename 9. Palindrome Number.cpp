class Solution {
public:
    bool isPalindrome(int x) 
    {
        if(x<0) return false;

        int len = 0, tmp = x;

        while(tmp) {tmp /= 10;++len;}
        
        int l = len;
        
        for(int i=1;i <= l/2;++i)
        {
            int a = x % ((int)pow(10, 1));
            int b = x / (pow(10, len-1));
            if (a != b) return false;
            len -= 2;
            x = x % ((int)pow(10, len+1));
            x /= 10;
        }
        return true;
    }
};

class Solution {
public:
    bool isPalindrome(int x) 
    {
        if(x<0 ||(x!=0 && x%10 ==0)) return false;

        int half = 0;
        
        while(x>half)
        {
            half = half*10 + x%10;
            x = x/10;
        }
        
        if(half == x || half/10 == x) return true;
        return false;
        
    }
};