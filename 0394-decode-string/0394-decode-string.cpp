class Solution {
public:
    
    bool isNumber(string s) {
        for (char c : s) if (!isdigit(c)) return false;
        return true;
    }
    
    string decodeString(string s) {
        stack<string> stk;
        for (char c : s) {
            if (c == '[') {
                stk.push(string(1, c));    
            }
            else if (c == ']') {
                string str = "";
                while (stk.top() != "[") {
                    str = stk.top() + str;
                    stk.pop();
                }
    
                stk.pop();

                int num = stoi(stk.top());
                stk.pop();
                string temp = "";
                while(num--) temp += str;

                stk.push(temp);
            }
            else {
                if (!stk.size() || stk.top() == "[" || isdigit(c) != isNumber(stk.top())) {
                    stk.push(string(1, c));
                }
                else {
                    string str = stk.top() + c;
                    stk.pop();
                    stk.push(str);
                }
            }            
        }

        string ans = "";
        while(stk.size()) {
            ans = stk.top() + ans;
            stk.pop();
        }
        return ans;
    }
};