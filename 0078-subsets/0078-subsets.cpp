class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back({});
        for (int n : nums){
            vector<vector<int>> temp = ans;
            for (auto &v : temp) v.push_back(n);
            for (auto v : temp) ans.push_back(v);
        }
            
        return ans;
    }
};