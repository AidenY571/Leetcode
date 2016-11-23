class Solution {
public:
    int numTrees(int n) 
    {
        vector<int> v(2,1);

        for(int i = 2; i <= n; i++)
        {
            int tmp = 0;

            for (int j = 0; j < i; ++j)
            {
                tmp += v[j]*v[i-1-j];
            }

            v.push_back(tmp);
        }

        return v[n];
    }
};