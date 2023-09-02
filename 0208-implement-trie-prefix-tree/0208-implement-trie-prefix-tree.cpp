class TrieNode {
public:
    TrieNode* children[26];
    bool isWord;
    
    TrieNode() {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
        isWord = false;
    }

};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        
        TrieNode* cur = root;
        
        for (char c : word) {
            int ind = c - 'a';
            if ( !(cur->children[ind]) ) cur->children[ind] = new TrieNode();
            cur = cur->children[ind];
        }
        
        cur->isWord = true;
        
    }
    
    bool search(string word) {
        
        TrieNode* cur = root;
        
        for (char c : word) {
            int ind = c - 'a';
            if ( !(cur->children[ind]) ) return false;
            cur = cur->children[ind];
        }
        
        return cur->isWord;
        
    }
    
    bool startsWith(string prefix) {
        
        TrieNode* cur = root;
        
        for (char c : prefix) {
            int ind = c - 'a';
            if ( !(cur->children[ind]) ) return false;
            cur = cur->children[ind];
        }
        
        return true;
        
    }
    
    TrieNode* root;
};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */