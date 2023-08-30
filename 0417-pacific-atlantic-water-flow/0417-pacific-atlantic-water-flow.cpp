class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n));
        vector<vector<bool>> atlantic(m, vector<bool>(n));
        
        for (int i = 0; i < m; i++) {
            
            spread( i, 0, heights, pacific, m, n );
            spread( i, n - 1, heights, atlantic, m, n );
            
        }
        
        for (int j = 0; j < n; j++) {
            
            spread( 0, j, heights, pacific, m, n );
            spread( m - 1, j, heights, atlantic, m, n );
            
        }
        
        vector<vector<int>> ret;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ( atlantic[i][j] && pacific[i][j] ) ret.push_back({i, j});
            }
        }
        return ret;
        
    }
    
    void spread( int i, int j, const vector<vector<int>>& heights, vector<vector<bool>>& visited, int m, int n ) {
        
        visited[i][j] = true;
        
        if ( i > 0 && !visited[i - 1][j] && heights[i - 1][j] >= heights[i][j] ) spread( i - 1, j, heights, visited, m, n );
        if ( i < m - 1 && !visited[i + 1][j] && heights[i + 1][j] >= heights[i][j] ) spread( i + 1, j, heights, visited, m, n );
        if ( j > 0 && !visited[i][j - 1] && heights[i][j - 1] >= heights[i][j] ) spread( i, j - 1, heights, visited, m, n );
        if ( j < n - 1 && !visited[i][j + 1] && heights[i][j + 1] >= heights[i][j] ) spread( i, j + 1, heights, visited, m, n );
    }
};