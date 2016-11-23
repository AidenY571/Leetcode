class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combine(int n, int k) 
    {
        vector<int> v;
        check(n, k, 1, v);
        return res;
    }

    void check(int &n, int &k, int index, vector<int> &v)
    {
        if(v.size() == k) 
        {
            res.push_back(v);
            return;
        }

        for (int i = index; i <= n; ++i)
        {
            v.push_back(i);
            check(n,k,i+1,v);
            v.pop_back();
        }
        return;
    }
};