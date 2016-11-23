class Solution {
public:
    int findNthDigit(int n) 
    {
        long long t = 0;

        int count = 0, past = 0,res = 0;

        while(t < n)
        {
            past = t;
            count++;
            t += 9*pow(10,count-1)*count;
            
        }
        
        n -= past;
        
        t = pow(10,count-1)-1 + n/count;

        if(n%count != 0)
        {
            ++t;
            int tmp = count - n%count;
            while(tmp)
            {
                t /= 10;
                tmp--;
            }
        }

        return t%10;
    }
};