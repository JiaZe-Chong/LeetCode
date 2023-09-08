class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> m;
        for (auto a : tickets) m[a[0]].insert( a[1] );\
            
        vector<string> ret;
        dfs( m, "JFK", ret );
        reverse( ret.begin(), ret.end() );
        return ret;
    }
    
    void dfs( unordered_map<string, multiset<string>>& m, string s, vector<string>& ret ) {
        
        while( !m[s].empty() ) {
            string next = *m[s].begin();
            m[s].erase( m[s].begin() );
            dfs( m, next, ret );
        }
        
        ret.push_back( s );
        
    }
};