class Solution {
public:
    int superPow(int a, vector<int>& b) 
    {
        a = a % 1337;

        int res = 1;
        
        for (int i = b.size() - 1; i >= 0; i--) 
        {
            res = res * mypow(a, b[i]) % 1337;
            a = mypow(a, 10);
        }

        return res;
    }

    int mypow(int a, int b)
    {
        int res = 1;

        while (b != 0) 
        {
            if (b % 2 != 0) res = res * a % 1337;

            a = a * a % 1337;

            b /= 2;
        }

        return res;
    }
};