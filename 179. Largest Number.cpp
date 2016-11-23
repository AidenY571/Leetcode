class Solution {
public:
    string largestNumber(vector<int>& nums) 
    {
        vector<string> snums;

        string largest;
        
        for(int i : nums) snums.push_back(to_string(i));
        
        sort(snums.begin(),snums.end(),[](string &a,string &b)
            {return a + b > b + a;});
        
        for(string s : snums) largest += s;
        
        if(largest[0] == '0' || !largest.size()) return "0";
        
        return largest;
    }
};