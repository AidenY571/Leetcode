class Solution {
public:
    int bulbSwitch(int n) 
    {
        int num = 0;
        
        for(int i = 1; i*i <= n; ++i)
            ++num;
        
        return num;
    }
};