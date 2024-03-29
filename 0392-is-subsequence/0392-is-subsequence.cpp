class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        
        for (char c : t) {
            if (c == s[i]) i++;
            if (i == s.length()) return true;
        }
            
        return i == s.length();
    }
};