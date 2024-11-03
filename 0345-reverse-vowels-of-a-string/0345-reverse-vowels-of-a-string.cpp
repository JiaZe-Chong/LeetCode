class Solution {
public:
    int isVowel(char c) {
        return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
               c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    
    string reverseVowels(string s) {
        stack<char> stk;
        
        for (const auto& c : s) {
            if (isVowel(c))
                stk.push(c);
        }
        
        for (auto& c : s) {
            if (isVowel(c)) {
                c = stk.top();
                stk.pop();
            }
        }
        
        return s;
    }
};