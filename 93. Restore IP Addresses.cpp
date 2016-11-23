class Solution {
public:
    vector<string> restoreIpAddresses(string s) 
    {
        vector<string> res;
        
        check(s,0,0,"",res);
        
        return res;
    }
    
    void check(string &s, int pos, int num, string t, vector<string> &res)
    {
        if(num == 4)
        {
            if(pos == s.size())
            {
                t.pop_back();
                res.push_back(t);
            }
            return;
        }
        
        int tmp = 0;
        for(int i = pos; i < s.size(); ++i)
        {
            tmp = tmp*10 + s[i]-'0';
            
            if(tmp > 255) break;
            
            t.push_back(s[i]);
            t.push_back('.');
            check(s,i+1,num+1,t,res);
            t.pop_back();
            if(s[i] == '0') break;
        }
    }
};