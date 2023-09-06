class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if ( s3.length() != s1.length() + s2.length() ) return false;
        return dfs( s1, s2, s3, 0, 0 );
    }
    
    bool dfs( string s1, string s2, string s3, int i, int j ) {
        
        if ( i == s1.length() && j == s2.length() ) return true;
        
        if ( m.find( {i, j} ) != m.end() ) return m[{i, j}];
        
        int ret = false;
        
        if ( i < s1.length() && s1[i] == s3[i + j] && dfs( s1, s2, s3, i + 1, j ) ) ret = true;
        else if ( j < s2.length() && s2[j] == s3[i + j] && dfs( s1, s2, s3, i, j + 1 ) ) ret = true;
        
        m[{i, j}] = ret;
        
        return ret;      
        
    }
    
    map< pair<int, int>, int > m;
};