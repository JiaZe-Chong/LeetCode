class Solution {
public:
    string reverseWords(string s) {
        
        stack<string> stk;
        
        string temp = "";
        
        for(int i = 0; i < s.length(); i++) {
            
            if (s[i] == ' ') {
                if (temp.length()){
                    stk.push(temp);
                    temp = "";
                } 
                continue;
            }
            else
                temp = temp + s[i];
            
        }
        if (temp.length()){
            stk.push(temp);
            temp = "";
        } 
    
        while(stk.size() > 1) {
            temp = temp + stk.top() + ' ';
            stk.pop();
        }
        
        return temp + stk.top();
    }
};