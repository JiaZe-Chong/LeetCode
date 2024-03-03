class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        
        for (const auto& interval : intervals) {
            if (!ans.size() || interval[0] > ans[ans.size() - 1][1]) {
                ans.push_back(interval);
            }
            else if (interval[0] <= ans[ans.size() - 1][1]) {
                ans[ans.size() - 1][1] = max(ans[ans.size() - 1][1], interval[1]);
            }
        }
        
        return ans;
    }
};