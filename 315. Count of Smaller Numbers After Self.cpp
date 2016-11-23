class Solution {
private:
    vector<int> bit;
    int len = 0;
public:
    vector<int> countSmaller(vector<int>& nums) 
    {
        len = nums.size();
        
        vector<int> res(len), sorted = nums;
        
        bit.resize(len+1);
        
        sort(sorted.begin(),sorted.end());
        
        unordered_map<int,int> dict;
        
        for(int i = 0; i < len; ++i) dict[sorted[i]] = i+1;
        
        for(int i = len-1 ; i >= 0; --i)
        {
            res[i] = bit_sum(dict[nums[i]]);
            bit_update(dict[nums[i]]);
        }
        
        return res;
    }
    
    void bit_update(int pos)
    {
         if(!len) return;
         
         for(int i = pos; i <= len; i += (i & -i))
         {
             ++bit[i];
         }
    }
    
    int bit_sum(int pos)
    {
        if(!len) return 0;
        
        int res = 0;
        
        for(int i = pos-1; i > 0; i -= (i &-i))
        {
            res += bit[i];
        }
        
        return res;
    }
};