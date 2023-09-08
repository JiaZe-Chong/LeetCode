class TrieNode {
public:
    
    TrieNode() {
        for (int i = 0; i < 26; i++) child[i] = nullptr;
    }
    
    TrieNode* child[26];
    bool isWord = false;
    
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        for ( string s : words ) insert(s);
        
        int m = board.size();
        int n = board[0].size();
        
        TrieNode* cur = root;
        vector<string> ret;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                search( board, i, j, m, n, cur, "", ret );
            }
        }
        
        return ret;
        
    }
    
    void insert( string s ) {
        
        TrieNode* cur = root;
        
        for ( char c : s ) {
            
            if ( !cur->child[ c - 'a' ] )
                cur->child[ c - 'a' ] = new TrieNode();
            cur = cur->child[ c - 'a' ];
            
        }
        
        cur->isWord = true;
        
    }
    
    void search( vector<vector<char>>& board, int i, int j, int m, int n, 
                 TrieNode* node, string word, vector<string>& ret ) {
        
        if ( i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '#' )
            return;
        
        char c = board[i][j];
        
        node = node->child[c - 'a'];
        if ( !node ) return;
        
        word += c;
        if ( node->isWord ) {
            ret.push_back( word );
            node->isWord = false;
        }
        
        board[i][j] = '#';
        
        search( board, i - 1, j, m, n, node, word, ret );
        search( board, i + 1, j, m, n, node, word, ret );
        search( board, i, j - 1, m, n, node, word, ret );
        search( board, i, j + 1, m, n, node, word, ret );
        
        board[i][j] = c;
    }
        
        
    TrieNode* root = new TrieNode();
};