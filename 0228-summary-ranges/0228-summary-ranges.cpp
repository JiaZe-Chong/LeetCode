class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<pair<int, int>> vpii;
        
        for (int num : nums) {
            if (vpii.empty() || num != vpii.back().second + 1)
                vpii.push_back({num, num});
            else
                vpii.back().second = num;
        }
        
        vector<string> ans;
        for (const auto& [o, t] : vpii) {
            if (o == t) {
                ans.push_back(to_string(o));
            }
            else {
                ans.push_back(to_string(o) + "->" + to_string(t));
            }
        }
        
        return ans;
    }
};