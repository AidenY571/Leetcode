//Method 1
class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        double logRes = log10(n)/log10(4);
        return (logRes - int(logRes) == 0) ? true : false; 
    }
};

//Method 2
class Solution {
public:
    bool isPowerOfTwo(int num) 
    {
        while (num && (num % 4 == 0)) num /= 4;

        return num == 1;
    }
};