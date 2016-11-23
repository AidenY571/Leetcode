class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<int> v;
        sort(candidates.begin(),candidates.end());
        find(candidates, target, 0,v);
        return res;
    }

    void find(vector<int>& candidates, int target,int index, vector<int> tmp)
    {
        if (target == 0)
        {   
            res.push_back(tmp);
         
            return;
        }

        if (target < 0) return;
        
        for (int i = index; i < candidates.size(); ++i)
        {
            if (target >= candidates[i])
            {
                tmp.push_back(candidates[i]);

                find(candidates,target-candidates[i],i,tmp);
               
                tmp.pop_back();
            }
        }

    }
};