class Solution {
public:
    double myPow(double x, int n) 
    {
        double res = 1;
        
        long absn = abs((long)n);
        
        while(absn)
        {
            if(absn & 1) res *= x;
            
            x *= x;
            
            absn >>= 1;
        }
        
        return (n<0? 1/res:res);
    }
};
