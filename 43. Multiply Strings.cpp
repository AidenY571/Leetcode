class Solution {
public:
    string multiply(string num1, string num2) 
    {
        int len1 = num1.size(), len2 = num2.size();
        
        string res(len1+len2,'0');
        
        for(int i = 0; i < len1; ++i)
        {
            if(!num1[i]) continue;
            
            int carry = 0;
            
            for(int j = 0; j < len2; ++j)
            {
                carry += res[i+j]-'0' + (num1[len1-1-i]-'0') * (num2[len2-1-j]-'0');

                res[i+j] = carry%10+'0';
                
                carry /= 10;
            }
            
            if(carry) res[i+len2] = (res[i+len2]-'0'+carry)%10+'0';
        }
        
        while(res.back() == '0' && res.size()>1)
        {
            res.pop_back();
        }
        
        reverse(res.begin(),res.end());
        
        return res;
    }
};