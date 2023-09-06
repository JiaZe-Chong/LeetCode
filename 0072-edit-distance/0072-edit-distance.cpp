class Solution {
public:
    int minDistance(string word1, string word2) {
     
        if ( word1.empty() && word2.empty() ) return 0;
        
        if ( word1.empty() || word2.empty() ) return 1;
        
        int w1 = word1.length();
        int w2 = word2.length();
        vector<vector<int>> vvi( w1 + 1, vector<int>( w2 + 1 ) );
        
        for (int i = 1; i <= w1; i++) vvi[i][0] = i;
        for (int j = 1; j <= w2; j++) vvi[0][j] = j;
        
        for (int i = 1; i <= w1; i++) {
            for (int j = 1; j <= w2; j++) {
                
                if ( word1[i - 1] == word2[j - 1] ) vvi[i][j] = vvi[i - 1][j - 1];
                else vvi[i][j] = min( vvi[i - 1][j - 1] ,min( vvi[i - 1][j], vvi[i][j - 1] ) ) + 1;
                
            }
        }
        
        return vvi[w1][w2];
        
    }
};