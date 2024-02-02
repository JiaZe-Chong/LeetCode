class Solution {
public:
    bool isVowel(const char& c) {
        return c == 'a' || c == 'e' || c == 'i' || c =='o' || c == 'u';
    }
    
    int maxVowels(string s, int k) {
        int ans = 0;
        int cur = 0;
        
        for (int i = 0; i < s.length(); i++) {
            
            if (i >= k) {
                ans = max(ans, cur);
                if (isVowel(s[i - k])) cur--;
            }
            
            if (isVowel(s[i])) cur++;
            
        }
        
        return max(ans, cur);
    }
};