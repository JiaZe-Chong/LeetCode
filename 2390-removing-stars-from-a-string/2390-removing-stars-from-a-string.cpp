class Solution {
public:
    string removeStars(string s) {
        int write = 0;
        
        for (char c : s) {
            if (c != '*') s[write++] = c;
            else write--;
        }
        
        return s.substr(0, write);
    }
};