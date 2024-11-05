class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        set<int> visited;
        int n = isConnected.size();
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            if (!visited.contains(i)) {
                dfs(i, visited, n, isConnected);
                ans++;
            }
        }
        
        return ans;
    }
    
    void dfs(int i, set<int>& visited, int n, const vector<vector<int>>& isConnected) {
        if (visited.contains(i))
            return;

        visited.insert(i);
        for (int j = 0; j < n; j++) {
            if (isConnected[i][j] && !visited.contains(j)) {
                dfs(j, visited, n, isConnected);
            }
        }
    }
};