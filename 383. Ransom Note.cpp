//Method 1 Compair String
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        for (auto i : ransomNote) 
        {
            auto pos = magazine.find(i);

            if (pos == string::npos) return false;
            
            magazine[pos] = '+';
        }
        return true;
    }
};

//Method 2 Sort
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        if (ransomNote == null || magazine == null || 
            ransomNote.length() > magazine.length()) return false;

        sort(ransomNote.begin(),ransomNote.end());
        sort(magazine.begin(),magazine.end());
    
        int i = 0, j = 0;

        while (j < s2.length && i < s1.length)
        {
            if (s1[i] ==  s2[j])
            {
                i++; j++;
            }
            else if (s1[i] < s2[j]) return false;
            
            else if (s1[i] > s2[j]) j++;
        }
    
    return i == s1.length;
}

//Method 3 Hashmap
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        unordered_map<char,int>m;
        
        for(char i : magazine) m[i]++;
        
        for(char i : ransomNote)
        {
            if(m[i]==0) return false;
            m[i]--;
        }
        return true;
    }
};