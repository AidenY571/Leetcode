class ValidWordAbbr {
public:

    unordered_map<string,int> m;
    unordered_set<string> s;
    
    ValidWordAbbr(vector<string> &dictionary) 
    {
        for (string i : dictionary)
        {
            if(s.find(i) != s.end()) continue;
            
            s.insert(i);
            
            if(i.size() < 3) m[i]++;

            m[i[0] + to_string(i.size()-2)+i.back()]++;
        }
    }

    bool isUnique(string word) 
    {
        if(word.size() < 3)
        {
            if(s.find(word) == s.end()) return m[word]==0;

            return  m[word]==1;
        }

        if(s.find(word) == s.end()) return m[word[0] + to_string(word.size()-2)+word.back()]==0;

        return  m[word[0] + to_string(word.size()-2)+word.back()] == 1;
    }
};