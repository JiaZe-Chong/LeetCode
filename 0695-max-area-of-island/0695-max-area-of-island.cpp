class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        int mx = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ( grid[i][j] ) {
                    int area = 0;
                    spread( i, j, grid, area );
                    mx = max( mx, area );
                }
            }
        }
        
        return mx;
    }
    
    void spread( int i, int j, vector<vector<int>>& grid, int& area ) {
        if ( i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || !grid[i][j] ) return;
                   
        grid[i][j] = 0;
        area++;
        spread( i - 1, j, grid, area );
        spread( i + 1, j, grid, area );
        spread( i, j - 1, grid, area );
        spread( i, j + 1, grid, area );    
    }
};