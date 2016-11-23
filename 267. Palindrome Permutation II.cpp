class Solution {
public:
    vector<string> generatePalindromes(string s) 
    {
        vector<string> res;
        
        if(s.empty()) return res;
        
        unordered_map<char,int>m;

        string mid,tmp;

        for(char i : s)  m[i]++;
        
        for (auto i :m)
        {
            if(i.second%2)
            {
                if(mid.empty()) mid.push_back(i.first);
                
                else return res;
            }

            tmp += string(i.second/2,i.first);
        }

        check(tmp,res,mid);

        return res;
    }

    void check(string tmp, vector<string> &res, string s)
    {
        if(tmp.empty())
        {
            res.push_back(s);
            return;
        }

        for (int i = 0; i < tmp.size(); ++i)
        {
            if(i && tmp[i] == tmp[i-1]) continue;
            
            char t = tmp[i];
            string m = string(1,tmp[i])+s+string(1,tmp[i]);
            tmp.erase(tmp.begin()+i);
            check(tmp,res,m);
            tmp.insert(i,1,t);
        }
    }
};