class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int> st;
        
        for(string s : tokens)
        {
            if(s == "+" || s == "-" || s == "*" ||s == "/")
            {
                int a = st.top(); st.pop();
                
                int b = st.top(); st.pop();
        
                switch(s[0])
                {
                    case '+': {st.push(a+b);break;}
                    case '-': {st.push(b-a);break;}
                    case '*': {st.push(a*b);break;}
                    case '/': {st.push(b/a);break;}
                }
            }
                
            else st.push(stoi(s));
        }
        
        return (st.empty()? 0 : st.top());
    }
};