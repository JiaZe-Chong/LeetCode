class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (!nums.size()) return {-1, -1};
        int t1 = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int t2 = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (t1 == t2) return {-1, -1};
        else return {t1, t2 - 1};
    }
};