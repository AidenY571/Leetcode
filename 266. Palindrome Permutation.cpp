class Solution {
public:
    bool canPermutePalindrome(string s) 
    {
        int sign = 0;

        unordered_map<char,int>mymap;

        for(char i : s) mymap[i]++;
        

        for (auto i : mymap)
        {
            if (i.second % 2 == 1) sign++;
            
            if (sign > 1) return false;
        }

        return true;
    }
};