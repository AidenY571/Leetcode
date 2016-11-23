class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<int> v;
        check(nums,v,0);
        return res;
    }

    void check(vector<int>&n, vector<int> &v, int index)
    {
        if(index >= n.size())
        {
            res.push_back(v);
            return;
        }

        for (int i = index; i < n.size();++i)
        {
            swap(n[index],n[i]);
            v.push_back(n[index]);
            check(n,v,index+1);
            swap(n[index],n[i]);
            v.pop_back();
        }
        return;
    }
};