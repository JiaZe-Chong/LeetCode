class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    
    int maxVowels(string s, int k) {
        int left = 0, right = 0, count = 0, ans = 0;
        
        while (right < s.length()) {
            count += isVowel(s[right++]);
            
            if (right - left == k) {
                ans = max(ans, count);
                count -= isVowel(s[left++]);
            }
        }
        
        return ans;
    }
};