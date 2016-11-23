class Solution {
public:
    int nthUglyNumber(int n) 
    {
        int a = 0, b = 0, c = 0;
        
        int v[n] ={1};
        
        for(int i = 1; i < n; ++i)
        {
            v[i] = min(v[a]*2,min(v[b]*3,v[c]*5));
            if(v[a]*2== v[i])++a;
            if(v[b]*3== v[i])++b;
            if(v[c]*5== v[i])++c;
        }
        return v[n-1];
    }
};