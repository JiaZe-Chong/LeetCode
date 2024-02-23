class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        for (int i = 1; i <= 9; i++ ) {
            vector<int> empty;
            dfs(k, n, ans, i, 0, empty);
        }
        
        return ans;
    }
    
    void dfs(const int& k, const int& n, vector<vector<int>>& ans, int num, int sum, vector<int>& cur) {
        
        if (cur.size() + 1 > k) return;
        
        if (sum + num == n && cur.size() + 1 == k) {
            cur.push_back(num);
            ans.push_back(cur);
            cur.pop_back();
            return;
        }
        
        cur.push_back(num);
        sum += num;
        for (int i = num + 1; i <= 9; i++) {            
            dfs(k, n, ans, i, sum, cur);
            
        }
        sum -= sum;
        cur.pop_back();
        
    }
};