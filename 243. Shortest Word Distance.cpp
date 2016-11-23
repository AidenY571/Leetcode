class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) 
    {
        int first = -1, second = -1, res = INT_MAX;

        for(int i = 0; i < words.size(); i++)
        {
            if (words[i] == word1) first = i;
            
            else if (words[i] == word2) second = i;
            
            if (first > -1 && second > -1)
            {
                res = min(res, abs(first-second));
            }
        }

        return res;
    }
};