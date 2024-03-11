class Solution {
public:
    string simplifyPath(string path) {
        
        stack<string> stk;
        string cur = "";
        
        for (char c : path) {
            if (c == '/') {
                if (cur != "") {
                    stk.push(cur);
                    cur = "";  
                }       
            }
            else {
                cur = cur + c;                
            }
        }
        
        if (cur != "") stk.push(cur);
        
        cur = "";
        int skip = 0;
        while (stk.size()) {
            string file = stk.top();
            stk.pop();
            if (file == "..") {
                skip++;
                continue;
            }
            else if (file == ".") {
                continue;
            }
            else {
                if (!skip) {
                    cur = file + cur;
                }
                else {
                    skip--;
                    continue;
                }
            }
            cur = "/" + cur;
        }     
        
        return cur == "" ? "/" : cur;
    }
};