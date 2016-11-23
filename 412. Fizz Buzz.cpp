class Solution {
public:
    vector<string> fizzBuzz(int n) 
    {
        vector<string> res(n);
        
        for(int i=1; i<=n; ++i)
        {
            if(!(i%3)) res[i-1] += "Fizz";

            if(!(i%5)) res[i-1] += "Buzz";
            
            if(res[i-1].empty()) 
                res[i-1] = to_string(i);
            
        }
        
        return res;
    }
};