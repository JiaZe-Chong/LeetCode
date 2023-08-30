class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        int num = 0;
        
        for (int i = 0; i < m; i++) {
            
            for (int j = 0; j < n; j++) {
                
             if ( grid[i][j] == '1' )    
                num++;
                spread( i, j, grid );
            }
            
        }
        
        return num;
    }
    
    void spread( int i, int j, vector<vector<char>>& grid ) {
        
        if ( i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0' ) return;
        grid[i][j] = '0';
        
        spread( i - 1, j, grid );
        spread( i + 1, j, grid );
        spread( i, j - 1, grid );
        spread( i, j + 1, grid );
        
    }
};