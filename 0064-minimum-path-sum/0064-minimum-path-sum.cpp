class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
                
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        
        auto cmp = [&](const auto& p1, const auto& p2){
            return cost[p1.first][p1.second] > cost[p2.first][p2.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        
        cost[0][0] = grid[0][0];
        
        pq.push({0, 0});
        
        while (pq.size()) {
            const auto [i, j] = pq.top();
            pq.pop();
            
            if (i == m - 1 && j == n - 1)
                return cost[i][j];
            
            if (i != m - 1) {
                if (cost[i+1][j] == INT_MAX) {
                    cost[i + 1][j] = cost[i][j] + grid[i + 1][j];
                    pq.push({i + 1, j});
                }
            }
            
            if (j != n - 1) {
                if (cost[i][j+1] == INT_MAX) {
                    cost[i][j+1] = cost[i][j] + grid[i][j + 1];
                    pq.push({i, j + 1});
                }
            }
            
        }
        
        return 0;
    }
};