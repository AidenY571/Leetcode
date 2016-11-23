class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        check(nums,0,{});
        return res;
    }
    
    void check(vector<int>& nums,int index, vector<int> v)
    {
        if(index == nums.size()) {res.push_back(v);return;}
        
        check(nums,index+1,v);
        v.push_back(nums[index]);
        check(nums,index+1,v);
    }
};