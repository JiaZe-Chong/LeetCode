class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int count = 0;
        int left = 0, right = costs.size() - 1;

        while(left < candidates)
            pq.push({costs[left], left++});
        
        while(costs.size() - right - 1 < candidates && right >= left)
            pq.push({costs[right], right--});
        
        while(k--) {
            int cost = pq.top().first;
            int pos = pq.top().second;
            pq.pop();
            
            ans += cost;
            if (right >= left) {
                if (pos <= left)
                    pq.push({costs[left], left++});
                else 
                    pq.push({costs[right], right--});
            }
            
        }
        
        return ans;
    }
};