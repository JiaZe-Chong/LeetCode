class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(ans, cur, 1, n, k);     
        return ans;
    }
    
    void dfs(vector<vector<int>>& ans, vector<int>& cur, int num, int n, int k) {
        if (cur.size() == k) {
            ans.push_back(cur);
            return;
        }
        
        for (int i = num; i <= n; i++) {
            cur.push_back(i);
            dfs(ans, cur, i + 1, n, k);
            cur.pop_back();
        }        
    }
    
    
    
    
    
    
};