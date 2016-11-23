class Solution {
public:
    vector<string> letterCombinations(string digits) 
    {
        if(digits.empty()) return {};
        
        vector<string> v ={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        vector<string> res;
        
        string s;
        
        check(digits, v, res, s,0);
        
        return res;
    }
    
    void check(string &s, vector<string> &v, vector<string> &res, string &tmp, int index)
    {
        if(index == s.size())
        {
            res.push_back(tmp);
            return;
        }
        
        for(char i : v[s[index]-'0'-2])
        {
            tmp.push_back(i);
            check(s,v,res,tmp,index+1);
            tmp.pop_back();
        }
        return;
    }
};