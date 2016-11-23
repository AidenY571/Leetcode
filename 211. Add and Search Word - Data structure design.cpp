// DFS
class TrieNode 
{
public:
    bool is_word = false;
    TrieNode* next[26];
    TrieNode() 
    {
        memset(next, NULL, sizeof(TrieNode*) * 26); 
    }
};

class WordDictionary {
public:
    // Adds a word into the data structure.
    void addWord(string word) 
    {
        TrieNode *tmp = root;
        
        for(char c : word)
        {
            if (!tmp->next[c - 'a']) tmp->next[c - 'a'] = new TrieNode();
            
            tmp = tmp->next[c - 'a'];
        }
        
        tmp->is_word = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) 
    {
        return check(word, root);
    }
   
    bool check(string word, TrieNode* node) 
    {
        for(int i = 0; i < word.size(); ++i)
        {
            if(word[i] == '.')
            {
                for(int j = 0; j < 26; ++j)
                {
                    if(node->next[j])
                    {
                        if(check(word.substr(i+1),node->next[j])) return true;
                    }
                }
                
                return false;
            }
            else
            {
                if(!node->next[word[i]-'a']) return false;
                node = node->next[word[i]-'a'];
            }
        }
        
        return node && node->is_word;
    }
private:
    TrieNode* root = new TrieNode();
};

//BFS
class TrieNode 
{
public:
    bool key = false;
    TrieNode* next[26];
    TrieNode() 
    {
        memset(next, NULL, sizeof(next)); 
    }
};

class WordDictionary {
private:
    TrieNode* root;
public:
    WordDictionary() 
    {
        root = new TrieNode();
    }
    
    
    // Adds a word into the data structure.
    void addWord(string word) 
    {
        TrieNode *p = root;

        for (auto i : word)
        {
            if (p->next[i - 'a'] == NULL)p->next[i - 'a'] = new TrieNode();
            
            p = p->next[i-'a'];
        }

        p->key = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) 
    {
        stack<TrieNode*> s;
        s.push(root);
        for (char i:word)
        {
            if(s.empty()) return false;

            stack<TrieNode*>tmp;

            while(!s.empty())
            {
                if(i == '.')
                {
                    for(auto j : s.top()->next)
                    {
                        if(j != NULL) tmp.push(j);
                    }
                }
                else
                {
                    if (s.top()->next[i-'a'] != NULL)
                    {
                        tmp.push(s.top()->next[i-'a']);
                    }
                }

                s.pop();
            }

            s = tmp;
        }

        while(!s.empty())
        {
            if (s.top()->key) return true;
            s.pop();
        }

        return false;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");