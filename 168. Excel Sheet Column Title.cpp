class Solution {
public:
    string convertToTitle(int n) 
    {
        string s;
        while(n)
        {
            s.push_back((n-1)%26 +'A');
            n = (n-1)/26;
        }
        return string(s.rbegin(),s.rend());
    }
};