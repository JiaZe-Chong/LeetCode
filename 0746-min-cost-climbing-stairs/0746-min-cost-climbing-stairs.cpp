class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> cum(n);
        
        for (int i = 0; i < n; i++) {
            if (i == 0 || i == 1) 
                cum[i] = cost[i];
            else
                cum[i] = min(cum[i - 1], cum[i - 2]) + cost[i];
        }
        
        return min(cum[n - 1], cum[n - 2]);
    }
};