class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> us;
        for ( string s : wordList ) us.insert( s );
        
        queue<string> q;
        q.push( beginWord );
        int result = 1;
        
        while( !q.empty() ) {
            int n = q.size();
            
            while ( n-- ) {
                string cur = q.front();
                q.pop();
                
                if ( cur == endWord ) return result;
                
                for (int i = 0 ; i < cur.length(); i++){
                    char c = cur[i];
                    for (int j = 0; j < 26; j++){
                        cur[i] = 'a' + j;
                        if ( us.find( cur ) != us.end() ) {
                            q.push( cur );
                            us.erase( cur );
                        }
                    }
                    cur[i] = c;
                }

            }
            
            result++;
        }
        
        return 0;
    }
};