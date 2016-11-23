class Solution {
public:
    vector<vector<int>> getFactors(int n) 
    {
        vector<vector<int>> res;
        backTrack(n, 2, {}, res);
        return res;
    }
    
    void backTrack(int n, int start, vector<int>path, vector<vector<int> >& res ) 
    {
        for(int i = start; i*i<=n; ++i) 
        {
            if(n%i == 0) 
            {
                path.push_back(i);
                backTrack(n/i, i, path, res);
                path.pop_back();
            }
        }
        
        if(!path.empty()) 
        {
            path.push_back(n);
            res.push_back(path);
        }
    }
};