class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> stk;
        vector<int> ans(n);
        
        for (int i = 0; i < n; i++) {
            while (stk.size() && temperatures[i] > temperatures[stk.top()]) {
                int cur = stk.top();
                ans[cur] = i - cur;
                stk.pop();
            }
            stk.push(i);
        }
        
        return ans;
    }
};