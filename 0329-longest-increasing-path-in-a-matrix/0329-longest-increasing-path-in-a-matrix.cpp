class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int ret = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ret = max( ret, dfs( matrix, -1, i, j ) );
            }
        }
        
        return ret;
    }
    
    int dfs( vector<vector<int>>& matrix, int prev, int i, int j ) {
        
        if ( i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || matrix[i][j] <= prev )
            return 0;
        
        if ( m.find( {i, j} ) != m.end() ) return m[{i, j}];
        
        int ret = 1;
        int cur = matrix[i][j];
        ret = max( ret, 1 + dfs( matrix, cur, i + 1, j ) );
        ret = max( ret, 1 + dfs( matrix, cur, i - 1, j ) );
        ret = max( ret, 1 + dfs( matrix, cur, i, j + 1 ) );
        ret = max( ret, 1 + dfs( matrix, cur, i, j - 1 ) );
    
        m[{i, j}] = ret;
        
        return ret;
        
    }
    
    map< pair<int, int>, int >m;
};