class Solution {
public:
    int countPrimes(int n) 
    {
       vector<int> v(n,0);

       for (int i = 2; i < n; ++i)
       {
            if (!v[i])
            {
                if (i*i > n) break; 

                for (int j = 2; i * j < n; j++)
                {
                    v[i*j] = 1;
                }
            }
       }

        int count = 0;

        for (int i = 2; i < n; i++) 
        {
            if (v[i] == 0) ++count;
        }
        
        return count;
    }
};