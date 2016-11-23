class Solution {
public:
    string addBinary(string a, string b) 
    {
        string s;
        int carry = 0, len1= a.size(), len2 = b.size();
        for (int i = 0; i < a.size() || i < b.size(); ++i)
        {
            if(i < len1) carry += a[len1-1-i]-'0';
            if(i < len2) carry += b[len2-1-i]-'0';
            s.push_back((carry % 2)+'0');
            carry /= 2;
        }
        if(carry)s.push_back(carry+'0');
        return string(s.rbegin(),s.rend());
    }
};