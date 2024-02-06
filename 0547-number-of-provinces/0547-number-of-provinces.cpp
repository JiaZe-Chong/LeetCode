class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size(), false);
        
        int ans = 0;
        for (int i = 0; i < isConnected.size(); i++) {
            if (!visited[i]) {
                dfs(isConnected, visited, i);
                ans++;
            }
        }
        
        return ans;
    }
    
    void dfs(const vector<vector<int>>& isConnected, vector<bool>& visited, int i) {
        
        if (visited[i]) return;
        
        visited[i] = true;
        
        for (int j = 0; j < isConnected.size(); j++) {
            if (isConnected[i][j])
                dfs(isConnected, visited, j);            
        }
        
    }
};