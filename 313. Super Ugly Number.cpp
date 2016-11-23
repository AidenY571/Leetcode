class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) 
    {
        int res[n]={0};
        int index[primes.size()]={0};
        res[0]=1;

        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < primes.size(); ++j)
            { 
                if(!res[i]) res[i] = primes[j]*res[index[j]];
                res[i] = min(res[i],primes[j]*res[index[j]]);
            }
            
            for (int j = 0; j < primes.size(); ++j)
            { 
                if(primes[j]*res[index[j]]==res[i]) index[j]++;
            }
        }
        
        return res[n-1];
    }
};

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) 
    {
        int len = primes.size(), next = 1;

        int index[len] = {0}, num[n+1]={0};

        for (int i = 0; i <= n; ++i)
        {
            num[i] = next;
            next = INT_MAX;
            for (int j = 0; j < len; ++j)
            {
                if(num[i] == primes[j] * num[index[j]]) ++index[j];
                next = min(next,primes[j] * num[index[j]]);
            }
        }

        return num[n-1];
    }
};