class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> sortedQueries = queries;
        
        //[size, right]
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        //query -> sizwe
        map<int, int> m;
        
        sort(intervals.begin(), intervals.end());
        sort(sortedQueries.begin(), sortedQueries.end());
        
        int i = 0;
        for (int query : sortedQueries) {
            
            while (i < intervals.size() && intervals[i][0] <= query) {
                pq.push({ intervals[i][1] - intervals[i][0] + 1, intervals[i][1] });
                i++;
            }
            
            while (pq.size() && pq.top().second < query)
                pq.pop();
            
            if (pq.size())
                m[query] = pq.top().first;
            else
                m[query] = -1;
            
            
        }
        
        vector<int> ans;
        for (int query : queries)
            ans.push_back(m[query]);
        
        return ans;
    }
};