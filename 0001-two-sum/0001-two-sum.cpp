class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> pi;
        for (int i = 0; i < nums.size(); i++){
            pi.push_back({nums[i], i});
        }
        sort(pi.begin(), pi.end());
        int l = 0, h = pi.size() - 1;
        while(l < h){
            int n = pi[l].first + pi[h].first;
            if (n < target) l++;
            else if (n > target) h--;
            else return {pi[l].second, pi[h].second};
        }
        return {pi[l].second, pi[h].second};
    }
};