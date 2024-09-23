class Solution {
public:
    string reversePrefix(string word, char ch) {
        stack<char> stk;
        
        for (char c : word) {
            stk.push(c);
            if (c == ch)
                break;
        }
        
        if (stk.size() == word.size() && ch != word[word.size() - 1])
            return word;
        
        string ans = "";
        int i = stk.size();
        while(stk.size()) {
            ans += stk.top();
            stk.pop();
        }
        
        return ans + word.substr(i);
    }
};