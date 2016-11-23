class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) 
    {
        int first = -1, second = -1, res = INT_MAX;

        for (int i = 0; i < words.size(); ++i)
        {
            if(words[i] == word1) first = i;

            else if(words[i] == word2) second = i;
            
            else continue;

            if(word1 == word2) swap(first,second);
            
            if(first >= 0 && second >= 0) res = min(res,abs(first-second));
        }
        
        return res;
    }
};