class Solution {
public:
    vector<string> res;
    vector<string> generateAbbreviations(string word) 
    {
        if(word.empty())return {""};
        check(word,0);
        return res;   
    }

    void check(string s, int index)
    {
        if(index >= s.size())
        {
            res.push_back(s);
            return;
        }
        
        for (int i = index; i < s.size(); ++i)
        {
            int len = i - index + 1;
            
            string tmp = s.substr(0,index)+to_string(len);
            
            if(i < s.size()-1) tmp += s.substr(i+1);
        
            check(tmp,i+2- len + len/10 +1);
        }
        
        check(s,index+1);
        
        return;
    }
};

class Solution {
public:
    vector<string> generateAbbreviations(string word) 
    {
        if (word.empty()) return {word};

        vector<string> result;

        generateHelper(word, result, 0, "");

        return result;
    }

    void generateHelper(string &word, vector<string> &result, int index, string level) 
    {
        if (index >= word.length()) 
        {
            result.push_back(level);
            return;
        }
        generateHelper(word, result, index + 1, level + word[index]);

        for (int i = index; i < word.length(); i++) 
        {
            int len = i - index + 1;
            string tmp = level + to_string(len);
            if(i < word.length() - 1) tmp += word[i + 1];
            generateHelper(word, result, i + 2, tmp);
        }
    }
};