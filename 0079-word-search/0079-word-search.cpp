class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size();
        int n = board[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ( board[i][j] == word[0] && dfs( word, board, i, j, 0 ))
                    return true;
            }
        }
        
        return false;
    }
    
    bool dfs( const string& word, vector<vector<char>>& board, int i, int j, int ind ) {
        
        if ( i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[ind] )
            return false;
        
        if ( ind == word.size() - 1 ) return true;
        
        char c = board[i][j];
        board[i][j] = ' ';
        
        if ( 
            dfs( word, board, i + 1, j, ind + 1 ) ||
            dfs( word, board, i - 1, j, ind + 1 ) ||
            dfs( word, board, i, j + 1, ind + 1 ) ||
            dfs( word, board, i, j - 1, ind + 1 )
           )
            return true;
        
        board[i][j] = c;
        
        return false;
    }
};