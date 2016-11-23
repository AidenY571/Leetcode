class Solution {
public:
    bool wordPattern(string pattern, string str) 
    {
        istringstream s(str);
        string word;
        unordered_map<char, string> m;
        unordered_map<string, char> n;

        for (char i : pattern)
        {
            if (!getline(s, word, ' ')) return false;

            if (m.count(i) && m[i] != word) return false;

            m[i] = word;

            if (n.count(word) && n[word] != i) return false;

            n[word] = i;
        }

        return !getline(s, word, ' ');   
    }
};