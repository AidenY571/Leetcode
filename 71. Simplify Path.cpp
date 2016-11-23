class Solution {
public:
    string simplifyPath(string path) 
    {
        string res;
        
        stack<string> s;
        
        int len = path.size();

        for(int i = 0; i < len; ++i)
        {
            if(path[i] == '/') continue;
            
            int end = i + 1;
            
            while(path[end] != '/' && end < len) ++end;
            
            string tmp = path.substr(i, end-i+1);
            
            if(tmp.back()=='/')tmp.pop_back();
            
            if(tmp =="..")
            {
                if(!s.empty()) s.pop();
            }
            
            else if(!tmp.empty() && tmp !=".") 
                s.push(tmp);
            
            i = end;
        }
        
        while(!s.empty())
        {
            res= "/" +s.top()+ res;
            s.pop();
        }
    
        if(res.empty()) return "/";
        
        return res;
    }
};