class WordDistance {
public:
    unordered_map<string,vector<int>> m;
    
    WordDistance(vector<string>& words) 
    {
        for (int i = 0; i < words.size(); ++i)
        {
            m[words[i]].push_back(i);
        }
    }
    int shortest(string word1, string word2) 
    {
        auto v1 = m[word1], v2 = m[word2];
        int res = INT_MAX, l1 = 0, l2 = 0;
        while(l1 < v1.size() && l2 < v2.size())
        {
            res = min(res,abs(v1[l1] - v2[l2]));

            v1[l1] > v2[l2]? ++l2:++l1;
        }
        return res;
    }
};
// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");