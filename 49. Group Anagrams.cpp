class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string,int> m;
        
        vector<vector<string>> res;

        for (auto i:strs)
        {
            string tmp = i;
            
            sort(tmp.begin(),tmp.end());
            
            if (m.count(tmp)) res[m[tmp]].push_back(i);
            else
            {
                m[tmp] = res.size();
                res.push_back({strs[i]});
            }
        }
        return res;
    }
};