class Solution {
public:
    int lmax = 0, lmin = INT_MAX, len = 0;
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) 
    {
        len = s.size();
        int v[len+1]={0};
        vector<string> res;
        v[0] = 1;

        for(auto i:wordDict)
        {
            lmax = max(lmax,(int)i.size());
            lmin = min(lmin,(int)i.size());
        }

        for (int i = 0; i < len; ++i)
        {
            for (int j = lmin; i-j+1 >= 0 && j <= lmax; ++j)
            {
                if(wordDict.count(s.substr(i-j+1,j))&& v[i-j+1])
                {
                    v[i+1]=1;
                    break;
                }
            }
        }

        if(v[len]) check(s,wordDict,v,res,len-1,"");
        
        return res;
    }

    void check(string &s, unordered_set<string>& wordDict, int v[], vector<string> &res, int pos, string tmp)
    {
        for(int i = lmin; i<= min(lmax, pos+1); ++i)
        {
            string t = s.substr(pos-i+1,i);
            
            if( v[pos-i+1] && wordDict.count(t) )
            {
                if(pos+1-i == 0) res.push_back(t + tmp);
                
                else check(s,wordDict, v, res, pos-i, " " + t + tmp);
            }
        }
    }
};