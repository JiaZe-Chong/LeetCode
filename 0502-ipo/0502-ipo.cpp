class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++) 
            pq.push({profits[i], capital[i]});
        
        while (k--) {
            vector<pair<int, int>> temp;
            while(pq.size() && pq.top().second > w) {
                temp.push_back(pq.top());
                pq.pop();
            }
            if (!pq.size())
                return w;
            
            w += pq.top().first;
            pq.pop();
            for (auto a : temp)
                pq.push(a);
        }

        return w;
    }
};