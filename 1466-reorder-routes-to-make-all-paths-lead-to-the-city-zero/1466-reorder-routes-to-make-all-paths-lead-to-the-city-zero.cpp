class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& connection : connections) {
            adj[connection[0]].push_back({connection[1], 1});
            adj[connection[1]].push_back({connection[0], 0});
        }
        return dfs(0, -1, adj);
    }
    
    int dfs(int node, int parent, const vector<vector<pair<int, int>>>& adj) {
        int ret = 0;
        for (auto& [neighbor, sign] : adj[node]) {
            if (neighbor != parent) {
                ret += sign;
                ret += dfs(neighbor, node, adj);
            }
        }
        return ret;
    }
};