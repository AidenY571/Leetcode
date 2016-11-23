class Solution {
public:
    int numWays(int n, int k) 
    {
        if(n<1 || k<1) return 0;
        int a = k, b = 0; k--;
        for (int i = 1; i < n; ++i)
        {
            int tmp = a;
            a = tmp*k + b*k;
            b = tmp;
        }
        return a + b;
    }
};