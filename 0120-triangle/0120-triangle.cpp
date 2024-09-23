class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> cost;
        
        for (auto row : triangle) {
            if (cost.empty())
                cost = row;
            else {
                vector<int> next_cost = row;
                for (int i = 0; i < next_cost.size(); i++) {
                    int m = INT_MAX;
                    if (i != 0) m = min(m, cost[i - 1]);
                    if (i != next_cost.size() - 1) m = min(m, cost[i]);
                    next_cost[i] += m;
                }
                cost = next_cost;
            }
        }
        
        int ans = INT_MAX;
        for (int i : cost)
            ans = min(ans, i);
        return ans;
    }
};