class Solution {
public:
    string addStrings(string num1, string num2) 
    {
        string sum;
        
        int carry = 0, len1 = num1.size(), len2 = num2.size();
        
        for(int i = 0; i < len1 || i < len2 || carry; ++i)
        {
            if(i < len1) carry += (num1[len1-1-i] - '0');
            
            if(i < len2) carry += (num2[len2-1-i] - '0');
            
            sum = to_string(carry%10) + sum;
            
            carry = carry / 10;
        }
        
        return sum;
    }
};