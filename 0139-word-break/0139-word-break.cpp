class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> us;
        for ( string s : wordDict ) us.insert( s );
        
        int n = s.length();
        vector<bool> vb( n + 1 );
        vb[0] = true;
        
        for (int i = 1; i <= s.length(); i++) {
            for (int j = i - 1; j >= 0; j-- ) {
                if ( vb[j] ) {
                    string cur = s.substr( j, i - j );
                    if ( us.find( cur ) != us.end() ) {
                        vb[i] = true;
                        break;
                    }
                }
            }
        }
        
        return vb[n];
    }
};