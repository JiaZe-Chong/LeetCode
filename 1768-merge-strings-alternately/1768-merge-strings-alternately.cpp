class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        int i = 0, j = 0;
        string ans = "";
        
        while( i < word1.length() && j < word2.length() ) {
            ans += word1[i++];
            ans += word2[j++];
        }
        
        for (; i < word1.length(); i++)
            ans += word1[i];
        
        for (; j < word2.length(); j++)
            ans += word2[j];
            
        return ans;
    }
};