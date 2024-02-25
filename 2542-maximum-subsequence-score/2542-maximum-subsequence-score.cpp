class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<pair<int, int>> vpii;
        
        for (int i = 0; i < n; i++)
            vpii.push_back({nums2[i], nums1[i]});
        sort(vpii.begin(), vpii.end(), greater<>());
        
        long long sum = 0;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            pq.push(vpii[i].second);
            sum += vpii[i].second;
            if (pq.size() < k) 
                continue;
            
            ans = max(ans, vpii[i].first * sum);
            sum -= pq.top();
            pq.pop();
        }
        
        return ans;
    }
};