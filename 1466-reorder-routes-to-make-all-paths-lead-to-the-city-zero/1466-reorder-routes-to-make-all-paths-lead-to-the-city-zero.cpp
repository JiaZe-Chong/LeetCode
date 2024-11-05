class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto connection : connections) {
            adj[connection[0]].push_back({connection[1], 1});
            adj[connection[1]].push_back({connection[0], 0});
        }
        return dfs(0, -1, adj);
    }
    
    int dfs(int cur, int from, const vector<vector<pair<int, int>>>& adj) {
        int ans = 0;
        for (const auto& [to, cost] : adj[cur]) {
            if (to != from) {
                ans += dfs(to, cur, adj);
                ans += cost;
            }
        }
        return ans;
    }
};