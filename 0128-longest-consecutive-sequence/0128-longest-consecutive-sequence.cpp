class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        int l = 0, r = 0;
        int m = 1;
        while(r < nums.size() - 1){
            r++;
            if (nums[r] == nums[r - 1]){
                l++;
                continue;
            }
            if (nums[r] - nums[r - 1] == 1)
            m = max(m, r - l + 1);
            else l = r;
        }
        return m;
    }
};