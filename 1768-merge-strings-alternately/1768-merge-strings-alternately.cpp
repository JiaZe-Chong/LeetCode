class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int ind1 = 0, ind2 = 0;
        
        while(ind1 < word1.length() && ind2 < word2.length()) {
            ans += word1[ind1++];
            ans += word2[ind2++];
        }
        
        if (ind1 < word1.length()) {
            ans += word1.substr(ind1);
        }
        else if (ind2 < word2.length()) {
            ans += word2.substr(ind2);
        }
        
        return ans;
    }
};