class Solution {
public:
    int countSubstrings(string s) {
        
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            middleOut( s, i, i, count );
            middleOut( s, i, i + 1, count );
        }        
        return count;

    }
    
    void middleOut( string s, int i, int j, int& count ) {
        
        while( i >= 0 && j < s.length() && s[i] == s[j] ) {
            
            i--;
            j++;
            count++;
            
        }
    
    }
};