class Solution {
public:
    string getPermutation(int n, int k) 
    {
        string s;

        int num = 1, a[n]={1};
        
        for (int i = 1; i <= n; ++i)
        {
            a[i] = i + 1;
            num *= i;
        }

        if(k-- > num) return s;

        for (int i = 0; i < n; ++i)
        {
            num /= n-i;

            s.push_back(a[k/num]+'0');

            for (int j = k/num; j < n-1; ++j)
            {
                a[j] = a[j+1];
            }
            
            k = k%num;
        }

        return s;
    }
};