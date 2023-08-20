class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<map<int,bool>> vmv(9);
        vector<map<int,bool>> vmh(9);
        
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if ( board[i][j] == '.' ) continue;
                
                int k = board[i][j] - '0';
                if ( vmv[i][k] ) return false;
                if ( vmh[j][k] ) return false;
                vmv[i][k] = vmh[j][k] = true;
            }
        }
        
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                map<int, bool> m;
                for (int k = 0; k < 3; k++){
                    for (int l = 0; l < 3; l++){
                        if ( board[i * 3 + k][j * 3 + l] == '.' ) continue;
                        int temp = board[i * 3 + k][j * 3 + l] - '0';
                        if ( m[temp] ) return false;
                        m[temp] = true;
                    }
                }
            }
        }
        
        return true;
    }
};