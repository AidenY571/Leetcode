//Method 1
class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        double logRes = log10(n)/log10(3);
        return (logRes - int(logRes) == 0) ? true : false; 
    }
};

//Method 2
class Solution {
public:
    bool isPowerOfTwo(int num) 
    {
        while (num && (num % 3 == 0)) num /= 3;

        return num == 1;
    }
};