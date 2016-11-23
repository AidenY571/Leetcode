class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> st;
        
        for(char c : s)
        {
            if(c == '{' || c == '[' || c=='(') st.push(c);

            else
            {
                if(st.empty()) return false;
                
                char tmp = st.top();
                
                st.pop();
                
                switch (c)
                {
                    case '}': if(tmp != '{') return false; else break;
                    case ']': if(tmp != '[') return false; else break;
                    case ')': if(tmp != '(') return false; else break;
                }
            }
        }
        return st.empty();
    }
};