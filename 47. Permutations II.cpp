class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        check(nums, 0);
        return res;
    }

    void check(vector<int>n, int index)
    {
        if(index == n.size())
        {
            res.push_back(n);
            return;
        }

        for (int i = index; i < n.size();++i)
        {
            if(i > index && n[i] == n[index]) continue;
            swap(n[index],n[i]);
            check(n, index+1);
        }
        return;
    }
};