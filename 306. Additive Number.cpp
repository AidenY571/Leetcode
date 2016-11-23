class Solution {
public:
    bool isAdditiveNumber(string num) 
    {
        for (int i = 1; i <= num.size()/2; ++i)
        {
            for (int j = 1; j <= (num.size()-i)/2; ++j)
            {
                if (check(num.substr(0,i),num.substr(i,j),num.substr(i+j))) return true;
            }
        }

        return false;
    }
    
    bool check(string num1, string num2, string remain)
    {
        if (num1.size()>1 && num1[0]=='0' || num2.size()>1 && num2[0]=='0') return false;
        
        string tmp = sum(num1,num2);

        if (tmp == remain) return true;
                    
        if(tmp.size() < remain.size() && tmp.compare(remain.substr(0,tmp.size()))==0)
        {
            return check(num2,tmp,remain.substr(tmp.size()));
        }
        else
            return false;

    }
    
    string sum(string num1, string num2)
    {
        int carry = 0;
        string res;

        for (int i = num1.size()-1, j = num2.size()-1; i>= 0 || j>=0; --i,--j)
        {
            int tmp = carry + (i>=0? num1[i]-'0':0) + (j>=0? num2[j]-'0':0);

            carry = tmp/10;

            res.push_back(tmp%10 + '0');
        }

        if(carry) res.push_back(carry+'0');
        reverse(res.begin(), res.end());
            return res;
    }
};