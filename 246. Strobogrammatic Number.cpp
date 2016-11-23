class Solution {
public:
    bool isStrobogrammatic(string num) 
    {
        int l = 0, r = num.size()-1;

        while(l <= r)
        {
            char tmp = num[l];
            
            switch (tmp)
            {
                case '6': tmp = '9';  break;
                case '9': tmp = '6';  break;
                case '0': tmp = '0';  break;
                case '1': tmp = '1';  break;
                case '8': tmp = '8';  break;
                default:  tmp = '*';  
            }
            
            if(tmp != num[r]) return false;
            ++l;
            --r;
        }
        
        return true;
    }
};

class Solution {
public:
    bool isStrobogrammatic(string num) 
    {
        string rotated;

        for (int i = num.size()-1; i >= 0; --i)
        {
            switch (num[i])
            {
                case '6': rotated.push_back('9'); continue;
                case '9': rotated.push_back('9'); continue;
                case '0': rotated.push_back('0'); continue;
                case '1': rotated.push_back('1'); continue;
                case '8': rotated.push_back('8'); continue;
                default:  rotated.push_back('*'); continue;
            }  
        }

        if(rotated == num) return true;
        return false;
    }
};