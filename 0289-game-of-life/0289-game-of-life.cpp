class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        queue<pair<int, int>> flip;
        
        for (int i = 0 ; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                int live = 0;
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        if (x == 0 && y == 0) continue;
                        if (i + x < 0 || i + x >= board.size() || j + y < 0 || j + y >= board[0].size()) continue;
                        live += board[i + x][j + y];
                    }
                }
                
                if (board[i][j]) {
                    if (live < 2) flip.push({i, j});
                    else if (live > 3) flip.push({i, j});
                }
                else {
                    if (live == 3) flip.push({i, j});
                }
            }
        }
        
        while (flip.size()) {
            auto [i, j] = flip.front();
            board[i][j] = 1 - board[i][j];
            flip.pop();
        }
    }
};