class Solution {
public:
    vector<string> findStrobogrammatic(int n) 
    {
        vector<string> res;
        
        if (n & 1) res = {"0", "1", "8"};
        
        else res = {""};
        
        vector<string> bases = {"00", "11", "69", "88", "96"};
        
        while (n > 1) 
        {
            n -= 2;
            
            vector<string> temp; 
            
            for (string s : res)
                for (int i = n < 2; i < 5; ++i)
                    temp.push_back(bases[i][0] + s + bases[i][1]);
                    
            res = move(temp);
        }
        return res;
    }
};