class Solution {
public:
    vector<string> res;

    vector<string> generateParenthesis(int n) 
    {
        dfs(n, n, "");
        return res;
    }

    void dfs(int l, int r, string s)
    {   
        if (!l && !r) res.push_back(s);

        if (l > 0) dfs(l-1, r, s+"(");

        if (r > l) dfs(l, r-1, s+")");
        
        return;
    }
};