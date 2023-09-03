class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        vector<vector<string>> ret;
        dfs( s, 0, cur, ret );
        return ret;
    }
    
    void dfs( string s, int start, vector<string>& cur, vector<vector<string>>& ret ) {
        
        if ( start == s.length() ) {
            ret.push_back( cur );
            return;
        }
        
        for (int i = start; i < s.length(); i++) {
            if ( isPalin( s, start, i ) ) {
                string str = s.substr( start, i - start + 1 );
                cur.push_back( str );
                dfs( s, i + 1, cur, ret );
                cur.pop_back();
            }   
        }
    }
    
    
    bool isPalin( string s, int left, int right ) {
        
        while ( left < right ) {
            if ( s[left] != s[right] ) return false;
            left++;
            right--;
        }
        return true;
        
    }
};