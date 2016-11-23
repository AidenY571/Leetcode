class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) 
    {
        unordered_map<string,int> m;
        
        vector<string> repeat;
        
        for(int i = 0; i + 9 < s.size(); ++i)
        {
            string tmp = s.substr(i,10);
            
            if(m.find(tmp) != m.end())
            {
                if(m[tmp]++ == 1) repeat.push_back(tmp);
            }
            else m[tmp] = 1;
        }
        
        return repeat;
    }
};

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) 
    {
        char flag[262144] ={0};
        vector<string> result;
        int len,DNA=0,i;
        if((len=s.length())< 11) return result;
        for(i = 0 ; i < 9; i++)
            DNA = DNA << 2| (s[i] - 'A' + 1) % 5;
        for(i = 9;i<len;i++)
        {
            DNA = (DNA<<2 & 0xFFFFF)|(s[i] - 'A' + 1)%5;
                if(!(flag[DNA>>2]&(1<<((DNA&3) << 1)))) 
                    flag[DNA>>2] |= (1<<((DNA&3) << 1));
                else if(!(flag[DNA>>2]&(2<<((DNA&3) << 1)))) 
                {
                    result.push_back(s.substr(i-9,10));
                    flag[DNA>>2] |= (2<<((DNA&3) << 1));
                }
        }
        return result;
    }
};