class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> spii;
        int ret = 0;
        int n = heights.size();
        
        for (int i = 0; i < n; i++) {
            while (spii.size() && heights[i] < spii.top().second ) {
                int height = spii.top().second;
                spii.pop();
                int width = spii.empty() ? i : i - spii.top().first - 1;
                ret = max(ret, height * width);
            }
            
            spii.push({i, heights[i]});        
        }
        
        while (spii.size()) {
            int height = spii.top().second;
            spii.pop();
            int width = spii.empty() ? n : n - spii.top().first - 1;
            ret = max(ret, height * width);
        }
        
        return ret;
    }
};