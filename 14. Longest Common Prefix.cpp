class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string s;
        
        if(strs.empty()) return s;
        
        for(int i = 0; i < strs[0].size(); ++i)
        {
            char tmp = strs[0][i];
            
            for(int j = 1; j < strs.size(); ++j)
            {
                 if(i >= strs[j].size() || strs[j][i] != tmp) return s;
            }
            s.push_back(tmp);
        }
        return s;
    }
};