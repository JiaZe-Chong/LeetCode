class Solution {
public:
    int numDistinct(string s, string t) {
        return dfs( s, t, 0, 0 );
    }
    
    int dfs( string& s, string& t, int i, int j ) {
        
        if ( j == t.length() ) return 1;
        
        if ( i == s.length() ) return 0;
        
        if ( m.find( {i, j} ) != m.end() ) return m[{i, j}];
        
        if (s[i] == t[j]) {
            m[{i, j}] = dfs(s, t, i + 1, j + 1) % 1000000007 + dfs(s, t, i + 1, j) % 1000000007 ;
        } else {
            m[{i, j}] = dfs(s, t, i + 1, j);
        }
        
        return m[{i, j}] % 1000000007;
    }
    
    map< pair<int, int>, int > m;
};