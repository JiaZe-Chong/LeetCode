class TrieNode {
public:
    TrieNode() {
        isWord = false;
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }
    
    TrieNode* children[26];
    bool isWord;
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        
        for (char c : word) {
            int ind = c - 'a';
            if ( !cur->children[ind] ) cur->children[ind] = new TrieNode();
            cur = cur->children[ind];
        }
        
        cur->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        return searchInNode( word, 0, cur );
    }
    
    bool searchInNode( string& word, int i, TrieNode* node ) {
        if ( !node ) return false;
        
        if ( i == word.length() ) return node->isWord;
        
        if ( word[i] != '.' ) return searchInNode( word, i + 1, node->children[word[i] - 'a'] );
        
        for (int j = 0; j < 26; j++) {
            if ( searchInNode( word, i + 1, node->children[j] ) ) return true;
        }
        
        return false;
    }
    
    TrieNode* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */