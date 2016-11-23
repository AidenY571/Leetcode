class TrieNode {
public:
    
    // Initialize your data structure here.
    TrieNode *next[26];
    int val=0;
    
    // Initialize your data structure here.
    TrieNode(int e)
    {
        memset(next, 0, sizeof(next));
        val = e;
    }
};

class Trie {

private:
    TrieNode* root;
    
public:
    Trie() 
    {
        root = new TrieNode(-1);
    }

    // Inserts a word into the trie.
    void insert(string s) 
    {
        TrieNode *p = root;

        for(int i = 0; i < s.size(); ++ i)
        {
            if(p -> next[s[i] - 'a'] == NULL) p -> next[s[i] - 'a'] = new TrieNode(0);
            p = p -> next[s[i] - 'a'];
        }
        
        p->val = 1;
    }

    // Returns if the word is in the trie.
    bool search(string s) 
    {
        TrieNode *p = root;
        for(int i = 0; i < s.size(); ++ i)
        {
            if(p -> next[s[i] - 'a'] == NULL) return false;
            p = p -> next[s[i] - 'a'];
        }
        
        if(p->val==1)return true;
        
        return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string s) 
    {
        TrieNode *p = root;
        for(int i = 0; i < s.size(); ++ i)
        {
            if(p -> next[s[i] - 'a'] == NULL) return false;
            p = p -> next[s[i] - 'a'];
        }

        return true;
    }

};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

class TrieNode {
    // Initialize your data structure here.
    public TrieNode next[] = new TrieNode[26];;
    public boolean end_node =false;
    public TrieNode() {}
}

public class Trie {
    private TrieNode root;
    
    public Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    public void insert(String word) 
    {
        TrieNode tmp = root;

        int len = word.length();

        for(int i = 0; i<len; ++i)
        {
            int t = word.charAt(i) - 'a';

            if(tmp.next[t] == null)
                tmp.next[t] = new TrieNode();
            
            tmp = tmp.next[t];
        }

        tmp.end_node = true;
    }

    // Returns if the word is in the trie.
    public boolean search(String word) 
    {
        TrieNode tmp = root;

        int len = word.length();

        for(int i = 0; i<len; ++i)
        {
            int t = word.charAt(i) - 'a';
            
            if(tmp.next[t] == null) return false;
            
            tmp = tmp.next[t];
        }

        if(tmp.end_node) return true;
        
        return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    public boolean startsWith(String prefix) 
    {
        TrieNode tmp = root;

        int len = prefix.length();
        
        for(int i = 0; i < len; ++i)
        {
            int t = prefix.charAt(i) - 'a';

            if(tmp.next[t] == null) return false;
            
            tmp = tmp.next[t];
        }
        return true;
    }
}

// Your Trie object will be instantiated and called as such:
// Trie trie = new Trie();
// trie.insert("somestring");
// trie.search("key");