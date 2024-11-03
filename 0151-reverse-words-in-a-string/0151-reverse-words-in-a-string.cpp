class Solution {
public:
    string reverseWords(string s) {
        stack<string> stk;
        string cur = "";
        
        for (const auto& c : s) {
            if (c == ' ') {
                if (cur.size()) {
                    stk.push(cur);
                    cur = "";
                }
            }
            else {
                cur += c;
            }            
        }
        
        string ans = cur.size() ? cur + " " : "";
        while(stk.size()) {
            ans += stk.top() + " ";
            stk.pop();
        }
        return ans.substr(0, ans.length() - 1);
    }
};