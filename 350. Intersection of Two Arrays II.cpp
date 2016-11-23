class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> res;
        
        unordered_map<int,int> m;
        
        for(int i : nums1) m[i]++;
        
        for(int i : nums2)
        {
            if(m[i] > 0)
            {
                m[i]--;
                res.push_back(i);
            }
        }
        
        return res;
    }
};