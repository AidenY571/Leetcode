//Method 1
class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        double logRes = log10(n)/log10(2);
        return (logRes - int(logRes) == 0) ? true : false; 
    }
};

//Method 2
class Solution {
public:
    bool isPowerOfTwo(int num) 
    {
        while (num && (num % 2 == 0)) num /= 2;

        return num == 1;
    }
};

//Method 3
class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        return (n>0&&((n&(n-1))==0));
    }
};