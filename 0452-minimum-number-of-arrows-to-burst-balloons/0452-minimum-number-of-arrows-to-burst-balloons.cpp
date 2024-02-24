class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for (auto a : points) pq.push({a[0], a[1]});
        
        int ans = 0;
        
        while(pq.size()) {
            ans++;
            int limit = pq.top().second;
            while(pq.size() && pq.top().first <= limit) {
                limit = min(limit, pq.top().second);
                pq.pop();
            }
        }
        
        return ans;
    }
};