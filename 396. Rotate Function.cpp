class Solution {
public:
    int maxRotateFunction(vector<int>& A) 
    {
        int res = 0, base = 0, len = A.size();
        
        for (int i = 0; i < len; ++i)
        {
            base += A[i];
            res += i * A[i];
        }
        
        int tmp = res;
        
        for (int i = 0; i < len-1; ++i)
        {
            tmp = tmp - base + len*A[i];
            res = max(tmp,res);
        }
        
        return res;
    }
};