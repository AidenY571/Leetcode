class Solution {
public:
    int mySqrt(int x) 
    {
        int a = 0, b = x/2+1,mid = 0;
        if(b > 46339) b = 46339;
        while(a<=b)
        {
            mid = (a+b)/2;
            if(mid*mid == x) return mid;
            if(mid*mid < x && (mid+1)*(mid+1)>x)return mid;
            mid*mid < x ? a = ++mid: b = --mid;
        }

        return mid;        
    }
};

class Solution {
public:
    int mySqrt(int x) 
    {
        long long r = x;
        while (r*r > x)
        r = (r + x/r) / 2;
        return r;        
    }
};