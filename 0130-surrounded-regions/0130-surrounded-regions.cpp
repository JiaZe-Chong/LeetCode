class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        int m = board.size();
        int n = board[0].size();
        
        for (int i = 0; i < m; i++) {
            
            if ( board[i][0] == 'O' ) spread( i, 0, board, m, n );
            if ( board[i][n - 1] == 'O' ) spread( i, n-1, board, m, n );
            
        }
        
        for (int j = 0; j < n; j++) {
            
            if ( board[0][j] == 'O' ) spread( 0, j, board, m, n );
            if ( board[m - 1][j] == 'O' ) spread( m-1, j, board, m, n );
            
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                if ( board[i][j] == 'E' ) board[i][j] = 'O';
                else board[i][j] = 'X';
                
            }
        }
        
    }
    
    void spread( int i, int j, vector<vector<char>>& board, int m, int n ) {
        
        if ( i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O' ) return;
        board[i][j] = 'E';
        spread( i-1, j, board, m, n );
        spread( i+1, j, board, m, n );
        spread( i, j-1, board, m, n );
        spread( i, j+1, board, m, n );
    }
};