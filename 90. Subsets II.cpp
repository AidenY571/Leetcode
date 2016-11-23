class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        check(nums,0,{});
        return res;
    }
    
    void check(vector<int>& nums,int index, vector<int> v)
    {
        if(index == nums.size()) {res.push_back(v);return;}
        
        v.push_back(nums[index]);
        
        check(nums,index+1,v);

        v.pop_back();

        if(!v.empty() && nums[index] == v.back()) return;

        check(nums,index+1,v);
    }
};