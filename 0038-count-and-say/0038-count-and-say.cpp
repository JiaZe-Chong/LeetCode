class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        
        string str = countAndSay(n - 1);
        
        stack<pair<int, int>> stk;
        
        for (char c : str) {
            int i = c - '0';
            if (!stk.size())
                stk.push({i, 1});
            else if (stk.top().first == i) {
                int count = stk.top().second + 1;
                stk.pop();
                stk.push({i, count});
            }
            else 
                stk.push({i, 1});
        }
        
        string ans = "";
        while(stk.size()) {
            auto [num, count] = stk.top();
            stk.pop();
            ans = to_string(count) + to_string(num) + ans;
        }
        
        return ans;
    }
};