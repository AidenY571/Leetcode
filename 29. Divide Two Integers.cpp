class Solution {
public:
    int divide(int dividend, int divisor) 
    {
        if(!dividend) return 0;
        
        int sign_a = 1, sign_b = 1;

        long dd = dividend, dr =divisor, res=0;

        if(dd<0){sign_a = -1; dd *= (-1);}

        if(dr<0){sign_b = -1; dr *= (-1);}
 
        
        while(dd >= dr)
        {
            if(dr == 1){ res = dd; break;}
            
            long tmp = dr;
            
            int count = 1;
            
            while(dd > (tmp << 1)){tmp = tmp << 1; count = count << 1;}

            dd -= tmp;

            res += count;
        }
        res = res*sign_a*sign_b;

        if(res >= INT_MAX) return INT_MAX;

        return res;
    }
};