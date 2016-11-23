class Solution {
public:
    bool isHappy(int n) 
    {
        if(n < 1) return false;
        
        unordered_set<int>s;
        
        while(n != 1)
        {
            if(s.find(n) != s.end()) return false;

            s.insert(n);

            int tmp= 0;

            while(n)
            {
                tmp += (n%10)*(n%10);
                n /= 10;
            }

            n = tmp;
        }
        
        return true;
    }
};