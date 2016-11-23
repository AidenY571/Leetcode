class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) 
    {
        unordered_map<char,int> chars;
        
        int max_len = 0, slow = 0;
        
        for(int fast = 0; fast < s.size(); ++fast)
        {
            chars[s[fast]]++;
                
            while(chars.size() > k)
            {
                chars[s[slow]]--;

                if(!chars[s[slow]]) chars.erase(s[slow]);
                
                slow++;
            }
            
            max_len = max(max_len, fast - slow + 1);
        }
        
        return max_len;
    }
};