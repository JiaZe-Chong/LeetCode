class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ret;
        
        for (const auto& interval : intervals) {
            if (!ret.size() || interval[0] > ret[ret.size() - 1][1]) {
                ret.push_back(interval);
            }
            else {
                ret[ret.size() - 1][1] = max(ret[ret.size() - 1][1], interval[1]);
            } 
        }
        
        return ret;
    }
};