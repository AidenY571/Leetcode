class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) 
    {
        unordered_set<string> head({beginWord}), tail({endWord}),tmpSet;
        
        int minPath = 2, headLen = 1, tailLen = 1;
        
        while(headLen && tailLen)
        {
            if(headLen > tailLen)   
            {
                swap(head, tail);
                swap(headLen, tailLen);
            }
            
            for(auto str:head)
            {
                for(int i = 0; i < str.size(); ++i)
                {
                    string tmp = str;
                    
                    for(char ch = 'a'; ch <= 'z'; ++ch)
                    {
                        tmp[i] = ch;
                        
                        if(tmp == str) continue;
                
                        if(tail.find(tmp) != tail.end()) return minPath;
                        
                        if(wordDict.find(tmp) != wordDict.end())
                        {
                            tmpSet.insert(tmp);
                            wordDict.erase(tmp);
                        }
                    }
                }
            }
            
            head = tmpSet;
            
            tmpSet.clear();
            
            headLen = head.size();
            
            ++ minPath;
        }
        
        return 0;
    }
};


class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string> &wordList) 
    {

        if(beginWord == endWord) return 2;

        int res = check(beginWord,endWord,wordList);

        if(res == 9999) return 0;

        return res;

    }
    int check(string beginWord, string endWord, unordered_set<string> wordList) 
    {
        if(beginWord == endWord) return 2;

        auto n = wordList.find(beginWord);

        if(n != wordList.end()) wordList.erase(n);

        int res = 9999;

        for (int i = 0; i < beginWord.size(); ++i)
        {
            string s = beginWord;
            for(char j = 'a'; j <= 'z'; j++)
            {
                s[i] = j;
                if(s == endWord) return 2;
                auto pos = wordList.find(s);
                if (pos != wordList.end())
                {
                    wordList.erase(pos);
                    res = min(res,ladderLength(s,endWord,wordList));
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string> &wordList) 
    {
        auto n = wordList.find(beginWord);

        if(n != wordList.end()) wordList.erase(n);
        
        if(beginWord == endWord) return 2;

        queue<string> v;
        
        v.push(beginWord);

        int len = 1;

        while(v.size())
        {
            int temp = v .size();
            
            for (int k = 0; k < temp;++k)
            {
                for (int i = 0; i < v.front().size(); ++i)
                {   
                    string tmp = v.front();
                    for(char j = 'a'; j <= 'z'; j++)
                    {
                        tmp[i] = j;

                        if(tmp == endWord) return ++len;
                        
                        auto pos = wordList.find(tmp);
                        
                        if (pos != wordList.end())
                        {
                            wordList.erase(pos);
                            
                            v.push(tmp);
                        }
                    }
                }
                
                v.pop();
            }
            len++;
        }
        
        return 0;
    }
};